#ifndef DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H


#include "iostream"
#include "../../main/queue/LinkedQueue.h"

using namespace std;

class LinkedQueueTest {
public:
    static void run() {
        LinkedQueue queue = LinkedQueue();

        queue.enqueue("1st");
        cout << queue.toString() << endl;

        queue.enqueue("2nd");
        cout << queue.toString() << endl;

        queue.enqueue("3rd");
        cout << queue.toString() << endl;

        queue.dequeue();
        cout << queue.toString() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDQUEUETEST_H
