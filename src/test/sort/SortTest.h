#ifndef DATA_STRUCTURE_LECTURE_SORTTEST_H
#define DATA_STRUCTURE_LECTURE_SORTTEST_H


#include "iostream"
#include "../../main/sort/SortableArray.h"
#include "../../main/sort/InsertionSortArray.h"
#include "../../main/sort/BubbleSortArray.h"

using namespace std;

class SortTest {
public:
    static void run() {
        InsertionSortArray<int> iArr = InsertionSortArray<int>(10);
        BubbleSortArray<int> bArr = BubbleSortArray<int>(10);

        test(iArr);
        test(bArr);
    };

    static void test(SortableArray<int> &arr) {
        addElems(arr);
        arr.print();

        arr.sort();
        arr.print();
    }

    static void addElems(SortableArray<int> &arr) {
        arr.add(5);
        arr.add(7);
        arr.add(2);
        arr.add(6);
        arr.add(9);
        arr.add(3);
    }
};


#endif //DATA_STRUCTURE_LECTURE_SORTTEST_H
