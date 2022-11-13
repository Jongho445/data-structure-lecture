#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACK_H


#include "string"
#include "../exception/StackEmpty.h"
#include "../linked_list/SLinkedList.h"

using namespace std;

template <typename E>
class LinkedStack {
public:
    LinkedStack(): linkedList(), length(0) {}

    int size() const { return length; }
    bool empty() const { return length == 0; }

    const E& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Top of isEmpty stack");
        }

        return linkedList.front();
    }

    void push(const E& elem) {
        linkedList.addFront(elem);
        length++;
    }

    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Pop from isEmpty stack");
        }

        linkedList.removeFront();
        length--;
    }
private:
    SLinkedList<E> linkedList;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
