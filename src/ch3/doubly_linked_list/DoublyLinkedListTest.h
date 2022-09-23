#ifndef DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H


#include "iostream"
#include "DLinkedList.h"

using namespace std;

class DoublyLinkedListTest {
public:
    static void run() {
        DLinkedList list = DLinkedList();

        // add elem to the front, 4 times
        list.addFront("1st");
        list.addFront("2nd");
        list.addFront("3rd");
        list.addFront("4th");

        cout << list.toString() << endl;

        // remove front elem, 2 times
        list.removeFront();
        list.removeFront();

        cout << list.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
