#ifndef DATA_STRUCTURE_LECTURE_DEQUESTACK_H
#define DATA_STRUCTURE_LECTURE_DEQUESTACK_H


#include "string"
#include "../queue/LinkedDeque.h"
#include "../exception/StackEmpty.h"

using namespace std;

typedef string Elem;
class DequeStack {
public:
    DequeStack(): deque() {}

    int size() const { return deque.size(); }
    bool empty() const { return deque.empty(); }

    const Elem& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("top of empty stack");
        }

        return deque.front();
    }

    void push(const Elem& elem) {
        deque.insertFront(elem);
    }

    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("pop of empty stack");
        }

        deque.removeFront();
    }

    string toString() { return deque.toString(); }
private:
    LinkedDeque deque;
};

#endif //DATA_STRUCTURE_LECTURE_DEQUESTACK_H
