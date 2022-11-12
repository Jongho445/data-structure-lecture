#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H

#include "iostream"
#include "../../main/stack/LinkedStack.h"

using namespace std;

class LinkedStackTest {
public:
    static void run() {
        // case string
        LinkedStack<string> B; // B = [], getSize = 0

        B.push("Bob"); // B = [Bob*], getSize = 1
        B.push("Alice"); // B = [Bob, Alice*], getSize = 2
        cout << B.top() << endl; // outputs: Alice

        B.pop(); // B = [Bob*]
        cout << B.top() << endl; // outputs: Bob

        B.push("Eve"); // B = [Bob, Eve*], getSize = 2
        cout << B.top() << endl; // outputs: Eve
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
