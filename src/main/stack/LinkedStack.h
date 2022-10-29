#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACK_H


#include "string"
#include "../exception/StackEmpty.h"
#include "../linked_list/SLinkedList.h"

using namespace std;

typedef string Elem;

class LinkedStack {
public:
    LinkedStack(): linkedList(), length(0) {}

    int size() const { return length; }
    bool empty() const { return length == 0; }

    const Elem& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Top of empty stack");
        }

        return linkedList.front();
    }

    void push(const Elem& elem) {
        linkedList.addFront(elem);
        length++;
    }

    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Pop from empty stack");
        }

        linkedList.removeFront();
        length--;
    }
private:
    SLinkedList<Elem> linkedList;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
