#ifndef DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H

#include "iostream"
#include "../../main/stack/ArrayStack.h"

using namespace std;

class ArrayStackTest {
public:
    static void run() {
        ArrayStack<int> A; // arr = [], getSize = 0

        A.push(7); // arr = [7*], getSize = 1
        A.push(13); // arr = [7, 13*], getSize = 2

        cout << A.top() << endl; // outputs: 13

        A.pop(); // arr = [7*]
        cout << A.top() << endl; // outputs: 7

        A.push(9); // arr = [7, 9*], getSize = 2
        cout << A.top() << endl; // arr = [7, 9*], outputs: 9

        A.pop(); // arr = [7*]
        cout << A.top() << endl; // outputs: 9
    }
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYSTACKTEST_H
