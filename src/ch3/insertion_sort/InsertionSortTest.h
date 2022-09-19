#ifndef DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H
#define DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H


#include "iostream"
#include "SortableArray.h"

using namespace std;

class InsertionSortTest {
public:
    static void run() {
        // given
        char data[] = {'c', 'a', 'd', 'b'};
        int size = sizeof(data) / sizeof(char);
        SortableArray *arr = new SortableArray(data, size);

        cout << arr->toString() << endl;

        // when sorting elems
        arr->insertionSort();

        //then
        cout << arr->toString() << endl;
    };
};


#endif //DATA_STRUCTURE_LECTURE_INSERTIONSORTTEST_H
