#ifndef DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUETEST_H
#define DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUETEST_H


#include "iostream"
#include "../../main/heap/VectorCompleteTree.h"
#include "../../main/heap/HeapPriorityQueue.h"

using namespace std;

class HeapPriorityQueueTest {
public:
    static void run() {
        HeapPriorityQueue<int> queue1 = createQueue1();

        queue1.insert(2);
        queue1.printQueue();

        HeapPriorityQueue<int> queue2 = createQueue2();
        queue2.printQueue();
        queue2.removeMin();
        queue2.printQueue();
    }

    static HeapPriorityQueue<int> createQueue1() {
        HeapPriorityQueue<int> queue = HeapPriorityQueue<int>();

        queue.insert(4);
        queue.insert(5);
        queue.insert(6);
        queue.insert(15);
        queue.insert(9);
        queue.insert(7);
        queue.insert(20);
        queue.insert(16);
        queue.insert(25);
        queue.insert(14);
        queue.insert(12);
        queue.insert(11);
        queue.insert(8);

        return queue;
    }

    static HeapPriorityQueue<int> createQueue2() {
        HeapPriorityQueue<int> queue = HeapPriorityQueue<int>();

        queue.insert(4);
        queue.insert(5);
        queue.insert(6);
        queue.insert(15);
        queue.insert(9);
        queue.insert(7);
        queue.insert(20);
        queue.insert(16);
        queue.insert(25);
        queue.insert(14);
        queue.insert(12);
        queue.insert(11);
        queue.insert(13);

        return queue;
    }
};

#endif //DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUETEST_H
