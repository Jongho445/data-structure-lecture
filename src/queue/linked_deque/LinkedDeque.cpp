#include "LinkedDeque.h"


LinkedDeque::LinkedDeque(): linkedList(), length(0) {}

int LinkedDeque::size() const { return length; }
bool LinkedDeque::empty() const { return linkedList.empty(); }

const Elem &LinkedDeque::front() const throw(DequeEmpty) { return linkedList.front(); }
const Elem &LinkedDeque::back() const throw(DequeEmpty) { return linkedList.back(); }

void LinkedDeque::insertFront(const Elem& e) {
    linkedList.addFront(e);
    length++;
}

void LinkedDeque::insertBack(const Elem& e) {
    linkedList.addBack(e);
    length++;
}

void LinkedDeque::removeFront() throw(DequeEmpty) {
    if (empty()) {
        throw DequeEmpty("removeFront of empty deque");
    }

    linkedList.removeFront();
    length--;
}

void LinkedDeque::removeBack() throw(DequeEmpty) {
    if (empty()) {
        throw DequeEmpty("removeBack of empty deque");
    }

    linkedList.removeBack();
    length--;
}

string LinkedDeque::toString() { return linkedList.toString(); }
