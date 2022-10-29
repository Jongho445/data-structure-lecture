#ifndef DATA_STRUCTURE_LECTURE_ARRAYQUEUETEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYQUEUETEST_H


#include "iostream"
#include "../../main/queue/array_queue/ArrayQueue.h"

using namespace std;

class ArrayQueueTest {
public:
    static void run() {
        ArrayQueue queue = ArrayQueue(3);

        queue.enqueue("1st");
        queue.enqueue("2nd");
        queue.enqueue("3rd");
        cout << queue.front() << endl;

        queue.dequeue();
        queue.dequeue();
        cout << queue.front() << endl;

        queue.enqueue("4th");
        queue.enqueue("5th");
        cout << queue.front() << endl;

        queue.dequeue();
        cout << queue.front() << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYQUEUETEST_H
