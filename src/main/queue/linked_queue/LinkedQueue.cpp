#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(): linkedList(), length(0) { }

int LinkedQueue::size() const { return length; }
bool LinkedQueue::empty() const { return length == 0; }

const Elem& LinkedQueue::front() const throw(QueueEmpty) {
    if (empty()) {
        throw QueueEmpty("front of empty queue");
    }

    return linkedList.front();
}

void LinkedQueue::enqueue(const Elem& elem) {
    linkedList.add(elem);
    linkedList.advance();
    length++;
}

void LinkedQueue::dequeue() throw(QueueEmpty) {
    if (empty()) {
        throw QueueEmpty("dequeue of empty queue");
    }

    linkedList.remove();
    length--;
}

string LinkedQueue::toString() { return linkedList.toString(); }
