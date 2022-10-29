#ifndef DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H
#define DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H

#include "string"
#include "../linked_list/DLinkedList.h"
#include "../exception/DequeEmpty.h"

using namespace std;

typedef string Elem;

class LinkedDeque {
public:
    LinkedDeque(): linkedList(), length(0) {}
    int size() const { return length; }
    bool empty() const { return linkedList.empty(); }

    const Elem& front() const throw(DequeEmpty) { return linkedList.front(); }
    const Elem& back() const throw(DequeEmpty) { return linkedList.back(); }

    void insertFront(const Elem& elem) {
        linkedList.addFront(elem);
        length++;
    }

    void insertBack(const Elem& elem) {
        linkedList.addBack(elem);
        length++;
    }

    void removeFront() throw(DequeEmpty) {
        if (empty()) {
            throw DequeEmpty("removeFront of empty deque");
        }

        linkedList.removeFront();
        length--;
    }

    void removeBack() throw(DequeEmpty) {
        if (empty()) {
            throw DequeEmpty("removeBack of empty deque");
        }

        linkedList.removeBack();
        length--;
    }

    string toString() { return linkedList.toString(); }
private:
    DLinkedList linkedList;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H
