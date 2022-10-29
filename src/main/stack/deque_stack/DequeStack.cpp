#include "DequeStack.h"

DequeStack::DequeStack(): deque() {}

int DequeStack::size() const { return deque.size(); }
bool DequeStack::empty() const { return deque.empty(); }

const Elem& DequeStack::top() const throw(StackEmpty) {
    if (empty()) {
        throw StackEmpty("top of empty stack");
    }

    return deque.front();
}

void DequeStack::push(const Elem& elem) {
    deque.insertFront(elem);
}

void DequeStack::pop() throw(StackEmpty) {
    if (empty()) {
        throw StackEmpty("pop of empty stack");
    }

    deque.removeFront();
}

string DequeStack::toString() { return deque.toString(); }
