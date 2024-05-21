// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

TEST(test_fill_border){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    int width = 3;
    int height = 5;
    int value = 30;
    Matrix_init(mat, width, height);
    Matrix_fill_border(mat, value);

    ASSERT_EQUAL(*Matrix_at(mat, 4, 2), value);

    delete mat; // delete the Matrix
    
    width = 1;
    height = 1;
    value = 255;
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, width, height);
    Matrix_fill(mat1, value);
    
    ASSERT_EQUAL(*Matrix_at(mat1, 0, 0), value);
    
    delete mat1;
    
    Matrix *mat2 = new Matrix;

    width = 20;
    height = 12;
    value = 0;
    Matrix_init(mat2, width, height);
    Matrix_fill_border(mat2, value);

    ASSERT_EQUAL(*Matrix_at(mat2, 11, 0), value);

    delete mat2; // delete the Matrix
    
    Matrix *mat3 = new Matrix;

    width = 5;
    height = 5;
    value = -5;
    Matrix_init(mat3, width, height);
    Matrix_fill_border(mat3, value);

    ASSERT_EQUAL(*Matrix_at(mat3, 0, 4), value);

    delete mat3; // delete the Matrix
    
}

TEST(test_print){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 1, 1);
    
    *Matrix_at(mat, 0, 0) = 42;
    ostringstream expected;
    expected << "1 1\n"
            << "42 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;

}

TEST(test_width_height){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 12, 4);

    ASSERT_EQUAL(Matrix_width(mat), 12);
    ASSERT_EQUAL(Matrix_height(mat), 4);

    delete mat; // delete the Matrix
    
}

TEST(test_row_col){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);
    
    Matrix_fill(mat, 0);
    
    int *ptr = Matrix_at(mat, 2, 2);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
    
    delete mat; // delete the Matrix
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 5, 5);

    ASSERT_EQUAL(Matrix_width(mat1), 5);
    ASSERT_EQUAL(Matrix_height(mat1), 5);

    Matrix_fill(mat1, 0);

    int *ptr1 = Matrix_at(mat1, 2, 3);
    ASSERT_EQUAL(Matrix_row(mat1, ptr1), 2);
    ASSERT_EQUAL(Matrix_column(mat1, ptr1), 3);
    ASSERT_EQUAL(*ptr1, 0);
    *ptr1 = 42;
    
    delete mat1;
    
}

TEST(test_max){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 0);

    *Matrix_at(mat, 2, 4) = 2;
    Matrix_max(mat);
    
    ASSERT_EQUAL(Matrix_max(mat), 2);

    delete mat; // delete the Matrix
    
    Matrix *mat1 = new Matrix;
    const int width = 3;
    const int height = 5;
    const int max_value = 99;
    Matrix_init(mat1, width, height);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            *Matrix_at(mat1,row,col) = row * width + col;
        }
    }
    *Matrix_at(mat1, 4, 2) = max_value;
    ASSERT_EQUAL(Matrix_max(mat1), max_value);
    
    delete mat1;
}

// overflow
TEST(test_column_of_min_value_in_row) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 2);

    *Matrix_at(mat, 2, 4) = 3;
    *Matrix_at(mat, 2, 3) = 1;
    Matrix_column_of_min_value_in_row(mat, 2, 0, Matrix_width(mat));

    delete mat; // delete the Matrix

    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 5, 5);
    Matrix_fill(mat1, 15);

    *Matrix_at(mat1, 0, 3) = 4;
    *Matrix_at(mat1, 0, 2) = 4;
    Matrix_column_of_min_value_in_row(mat1, 0, 0, Matrix_width(mat1));
    delete mat1;

}

TEST(test_min_value_in_row){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 3);

    *Matrix_at(mat, 2, 1) = 0;
    *Matrix_at(mat, 2, 2) = 1;
    *Matrix_at(mat, 2, 4) = 2;

//    Matrix_min_value_in_row(mat, 2, 0, Matrix_width(mat));
    
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, Matrix_width(mat)), 0);

    delete mat; // delete the Matrix
    
    Matrix *mat1 = new Matrix;
    Matrix_init(mat1, 8, 8);
    Matrix_fill(mat1, 3);

    *Matrix_at(mat1, 2, 1) = 0;
    *Matrix_at(mat1, 2, 2) = 1;
    *Matrix_at(mat1, 2, 4) = 2;

    Matrix_min_value_in_row(mat1, 2, 0, Matrix_width(mat1));

    delete mat1; // delete the Matrix
    
    Matrix *mat2 = new Matrix;
    Matrix_init(mat2, 1, 1);
    Matrix_fill(mat2, -10);

    *Matrix_at(mat2, 0, 0) = -12;
    Matrix_min_value_in_row(mat2, 0, 0, Matrix_width(mat2));

    delete mat2; // delete the Matrix

}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
