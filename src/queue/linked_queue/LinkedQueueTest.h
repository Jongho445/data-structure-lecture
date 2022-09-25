#ifndef DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H


#include "iostream"
#include "LinkedQueue.h"

using namespace std;

class LinkedQueueTest {
public:
    static void run() {
        LinkedQueue queue = LinkedQueue();

        queue.enqueue("hello");
        cout << queue.front() << endl;

        queue.enqueue("haha");
        cout << queue.front() << endl;

        queue.dequeue();
        cout << queue.front() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H
