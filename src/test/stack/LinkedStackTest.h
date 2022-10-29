#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H

#include "iostream"
#include "../../main/stack/linked_stack/LinkedStack.h"

using namespace std;

class LinkedStackTest {
public:
    static void run() {
        // case string
        LinkedStack B; // B = [], size = 0

        B.push("Bob"); // B = [Bob*], size = 1
        B.push("Alice"); // B = [Bob, Alice*], size = 2
        cout << B.top() << endl; // outputs: Alice

        B.pop(); // B = [Bob*]
        cout << B.top() << endl; // outputs: Bob

        B.push("Eve"); // B = [Bob, Eve*], size = 2
        cout << B.top() << endl; // outputs: Eve
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
