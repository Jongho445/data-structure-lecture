#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H

#include "iostream"
#include "../../main/stack/LinkedStack.h"

using namespace std;

class LinkedStackTest {
public:
    static void run() {
        // case string
        LinkedStack<string> B; // B = [], getLength = 0

        B.push("Bob"); // B = [Bob*], getLength = 1
        B.push("Alice"); // B = [Bob, Alice*], getLength = 2
        cout << B.top() << endl; // outputs: Alice

        B.pop(); // B = [Bob*]
        cout << B.top() << endl; // outputs: Bob

        B.push("Eve"); // B = [Bob, Eve*], getLength = 2
        cout << B.top() << endl; // outputs: Eve
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACKTEST_H
