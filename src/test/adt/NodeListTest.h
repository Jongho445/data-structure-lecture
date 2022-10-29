#ifndef DATA_STRUCTURE_LECTURE_NODELISTTEST_H
#define DATA_STRUCTURE_LECTURE_NODELISTTEST_H


#include "iostream"
#include "../../main/adt/node_list/NodeList.h"

using namespace std;

class NodeListTest {
public:
    static void run() {
        NodeList list = NodeList();

        list.insertFront("1st");
        list.insertFront("2nd");
        list.insertFront("3rd");

        Iterator iterator1 = list.begin();
        cout << *iterator1 << endl;

        list.eraseFront();

        Iterator iterator2 = list.begin();
        cout << *iterator2 << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_NODELISTTEST_H
