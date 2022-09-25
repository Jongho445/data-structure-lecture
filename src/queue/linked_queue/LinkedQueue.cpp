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
    return C.front(); // list front is queue front
}

void LinkedQueue::enqueue(const Elem& e) {
    C.add(e); // insert after cursor
    C.advance(); // ...and advance
    n++;
}
// dequeue element at front
void LinkedQueue::dequeue() throw(QueueEmpty) {
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    C.remove(); // remove from list front
    n--;
}