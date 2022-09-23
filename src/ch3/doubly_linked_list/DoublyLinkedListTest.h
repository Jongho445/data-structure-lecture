#ifndef DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H


#include "iostream"
#include "DLinkedList.h"

using namespace std;

class DoublyLinkedListTest {
public:
    static void run() {
        // given
        DLinkedList list = DLinkedList();

        list.addFront("a");
        list.addFront("b");
        list.addFront("c");
        list.addFront("d");

        cout << list.toString() << endl;

        // when: remove front elem 2 times
        list.removeFront();
        list.removeFront();

        // then
        cout << list.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
