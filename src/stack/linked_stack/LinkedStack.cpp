#include "LinkedStack.h"

LinkedStack::LinkedStack(): linkedList(), length(0) { }

int LinkedStack::size() const {
    return length;
}

bool LinkedStack::empty() const {
    return length == 0;
}

const Elem& LinkedStack::top() const throw(StackEmpty) {
    if (empty()) {
        throw StackEmpty("Top of empty stack");
    }

    return linkedList.front();
}

void LinkedStack::push(const Elem& e) {
    linkedList.addFront(e);
    ++length;
}

void LinkedStack::pop() throw(StackEmpty) {
    if (empty()) {
        throw StackEmpty("Pop from empty stack");
    }

    linkedList.removeFront();
    --length;
}
