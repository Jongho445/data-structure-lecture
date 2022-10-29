#ifndef DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H
#define DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H

#include <string>
#include "../exception/QueueFull.h"
#include "../exception/QueueEmpty.h"
#include "../linked_list/CircleList.h"

using namespace std;

typedef string Elem;

class ArrayQueue {
public:
    ArrayQueue(int capacity) {
        arr = new Elem[capacity];
        this->capacity = capacity;
        length = 0;
        head = 0;
        rear = 0;
    };

    int size() const { return length; };
    bool empty() const { return length == 0; };

    const Elem& front() const throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("front of empty queue");
        }

        return arr[head];
    };

    void enqueue(const Elem& elem) {
        if (length >= capacity) {
            throw QueueFull("queue is full");
        }

        arr[rear] = elem;

        rear = (rear + 1) % capacity;
        length++;
    };

    void dequeue() throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("dequeue of empty queue");
        }

        head = (head + 1) % capacity;
        length--;
    };

private:
    Elem *arr;
    int capacity;

    int length;
    int head;
    int rear;
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYQUEUE_H
