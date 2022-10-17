#include "LinkedDeque.h"


LinkedDeque::LinkedDeque(): D(), n(0) {}

int LinkedDeque::size() const {
    return n;
}

bool LinkedDeque::empty() const {
    return D.empty();
}

const Elem &LinkedDeque::front() const throw(DequeEmpty) {
    return D.front();
}

const Elem &LinkedDeque::back() const throw(DequeEmpty) {
    return D.back();
}

void LinkedDeque::insertFront(const Elem& e) {
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem& e) {
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront() throw(DequeEmpty) {
    if (empty()) {
        throw DequeEmpty("removeFront of empty deque");
    }

    D.removeFront();
    n--;
}

void LinkedDeque::removeBack() throw(DequeEmpty) {
    if (empty()) {
        throw DequeEmpty("removeBack of empty deque");
    }

    D.removeBack();
    n--;
}

string LinkedDeque::toString() {
    return D.toString();
}
