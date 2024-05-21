// resize.cpp
// Project UID af1f95f547e44c8ea88730dfb185559d

//#include "stats.h"
//#include "p1_library.h"
#include <iostream>
#include <fstream>
#include "Image.h"
//#include "processing_public_tests.cpp"
using namespace std;

int main(int argc, char * argv[]) {
    if (argc != 4 || argc != 5) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" <<
        "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
   
