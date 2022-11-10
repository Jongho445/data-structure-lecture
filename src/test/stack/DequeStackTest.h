#ifndef DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H
#define DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H


#include "iostream"
#include "../../main/stack/DequeStack.h"

using namespace std;

class DequeStackTest {
public:
    static void run() {
        DequeStack<string> dequeStack = DequeStack<string>();

        dequeStack.push("1st");
        dequeStack.push("2nd");
        dequeStack.push("3rd");

        cout << dequeStack.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_DEQUESTACKTEST_H
