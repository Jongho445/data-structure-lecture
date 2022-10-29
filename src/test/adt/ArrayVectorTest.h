#ifndef DATA_STRUCTURE_LECTURE_ARRAYVECTORTEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYVECTORTEST_H


#include "iostream"
#include "../../main/adt/array_vector/ArrayVector.h"

using namespace std;

class ArrayVectorTest {
public:
    static void run() {
        ArrayVector vector;

        vector.insert(0, "1st");
        vector.insert(0, "2nd");
        vector.insert(0, "3rd");
        cout << vector[0] << endl;

        vector.erase(0);
        cout << vector[0] << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYVECTORTEST_H
