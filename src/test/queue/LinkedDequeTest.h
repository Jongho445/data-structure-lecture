#ifndef DATA_STRUCTURE_LECTURE_LINKEDDEQUETEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDDEQUETEST_H


#include "iostream"
#include "../../main/queue/LinkedDeque.h"

using namespace std;

class LinkedDequeTest {
public:
    static void run() {
        LinkedDeque deque = LinkedDeque();
        
        deque.insertFront("1st");
        deque.insertFront("2nd");

        cout << deque.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDDEQUETEST_H
