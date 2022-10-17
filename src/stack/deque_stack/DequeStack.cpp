#include "DequeStack.h"

DequeStack::DequeStack(): D() {}

int DequeStack::size() const {
    return D.size();
}

bool DequeStack::empty() const {
    return D.empty();
}

const Elem& DequeStack::top() const throw(StackEmpty) {
    if (empty())
        throw StackEmpty("top of empty stack");
    return D.front();
}

void DequeStack::push(const Elem& e) {
    D.insertFront(e);
}

void DequeStack::pop() throw(StackEmpty) {
    if (empty())
        throw StackEmpty("pop of empty stack");
    D.removeFront();
}

string DequeStack::toString() {
    return D.toString();
}
