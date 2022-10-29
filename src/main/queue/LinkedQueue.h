#ifndef DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H
#define DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H


#include "string"
#include "../exception/QueueEmpty.h"
#include "../linked_list/CircleList.h"

using namespace std;

typedef string Elem;

class LinkedQueue {
public:
    LinkedQueue(): linkedList(), length(0) { }

    int size() const { return length; }
    bool empty() const { return length == 0; }

    const Elem& front() const throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("front of empty queue");
        }

        return linkedList.front();
    }

    void enqueue(const Elem& elem) {
        linkedList.add(elem);
        linkedList.advance();
        length++;
    }

    void dequeue() throw(QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("dequeue of empty queue");
        }

        linkedList.remove();
        length--;
    }

    string toString() { return linkedList.toString(); }
private:
    CircleList linkedList;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H
