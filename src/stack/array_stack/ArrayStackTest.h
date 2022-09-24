#ifndef DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H

#include "iostream"
#include "ArrayStack.h"

using namespace std;

class ArrayStackTest {
public:
    static void run() {
        // case int
        ArrayStack<int> A; // A = [], size = 0

        A.push(7); // A = [7*], size = 1
        A.push(13); // A = [7, 13*], size = 2

        cout << A.top() << endl; // outputs: 13

        A.pop(); // A = [7*]
        cout << A.top() << endl; // outputs: 7

        A.push(9); // A = [7, 9*], size = 2
        cout << A.top() << endl; // A = [7, 9*], outputs: 9

        A.pop(); // A = [7*]
        cout << A.top() << endl; // outputs: 9

        // case string
        ArrayStack<string> B(10); // B = [], size = 0

        B.push("Bob"); // B = [Bob*], size = 1
        B.push("Alice"); // B = [Bob, Alice*], size = 2
        cout << B.top() << endl; // outputs: Alice

        B.pop(); // B = [Bob*]
        cout << B.top() << endl; // outputs: Bob

        B.push("Eve"); // B = [Bob, Eve*], size = 2
        cout << B.top() << endl; // outputs: Eve
    }
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H
