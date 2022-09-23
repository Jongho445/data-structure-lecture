#ifndef DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H
#define DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H


#include "iostream"
#include "SortableArray.h"

using namespace std;

class InsertionSortTest {
public:
    static void run() {
        // given
        SortableArray arr = SortableArray(10);
        arr.add('c');
        arr.add('a');
        arr.add('d');
        arr.add('b');

        cout << arr.toString() << endl;

        // when: sorting elems
        arr.insertionSort();

        //then
        cout << arr.toString() << endl;
    };
};


#endif //DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H
