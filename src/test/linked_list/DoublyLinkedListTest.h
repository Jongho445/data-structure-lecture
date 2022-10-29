#ifndef DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H


#include "iostream"
#include "../../main/linked_list/DLinkedList.h"

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

        cout << "\n" + list.toString() + "\n" << endl;

        // remove front elem, 2 times
        list.removeFront();
        list.removeFront();

        cout << list.toString() + "\n" << endl;

        // add "5th elem" between "2nd elem" and "1st elem"
        DNode *targetNode = list.header->next->next;
        list.add(targetNode, "5th");

        cout << list.toString() + "\n" << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_DOUBLYLINKEDLISTTEST_H
