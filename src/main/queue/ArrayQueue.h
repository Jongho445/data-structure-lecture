#ifndef DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H
#define DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H

#include <string>
#include "../exception/QueueFull.h"
#include "../exception/QueueEmpty.h"
#include "../linked_list/CircleList.h"

using namespace std;

template <typename E>
class ArrayQueue {
public:
    ArrayQueue(int capacity) {
        arr = new E[capacity];
        this->capacity = capacity;
        length = 0;
        head = 0;
        rear = 0;
    };

    int size() const { return length; };
    bool empty() const { return length == 0; };

    const E& front() const throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("front of isEmpty queue");
        }

        return arr[head];
    };

    void enqueue(const E& elem) {
        if (length >= capacity) {
            throw QueueFull("queue is full");
        }

        arr[rear] = elem;

        rear = (rear + 1) % capacity;
        length++;
    };

    void dequeue() throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("dequeue of isEmpty queue");
        }

        head = (head + 1) % capacity;
        length--;
    };

private:
    E *arr;
    int capacity;

    int length;
    int head;
    int rear;
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H
