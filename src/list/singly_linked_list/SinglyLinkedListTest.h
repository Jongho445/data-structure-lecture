#ifndef DATA_STRUCTURE_LECTURE_SINGLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_SINGLYLINKEDLISTTEST_H


#include "StringLinkedList.h"
#include "iostream"

using namespace std;

class SinglyLinkedListTest {
public:
    static void run() {
        StringLinkedList list = StringLinkedList();

        // add elem to the front, 4 times
        list.addFront("cat");
        list.addFront("dog");
        list.addFront("lion");
        list.addFront("tiger");

        cout << list.toString() << endl;

        // remove front elem, 2 times
        list.removeFront();
        list.removeFront();

        cout << list.toString() << endl;
    };
};


#endif //DATA_STRUCTURE_LECTURE_SINGLYLINKEDLISTTEST_H
