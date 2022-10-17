#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(): C(), n(0) { }

int LinkedQueue::size() const {
    return n;
}

bool LinkedQueue::empty() const {
    return n == 0;
}

const Elem& LinkedQueue::front() const throw(QueueEmpty) {
    if (empty())
        throw QueueEmpty("front of empty queue");
    return C.front();
}

void LinkedQueue::enqueue(const Elem& e) {
    C.add(e);
    C.advance();
    n++;
}

void LinkedQueue::dequeue() throw(QueueEmpty) {
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    C.remove();
    n--;
}

string LinkedQueue::toString() {
    return C.toString();
}
