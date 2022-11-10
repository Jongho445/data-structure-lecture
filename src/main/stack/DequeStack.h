#ifndef DATA_STRUCTURE_LECTURE_DEQUESTACK_H
#define DATA_STRUCTURE_LECTURE_DEQUESTACK_H


#include "string"
#include "../queue/LinkedDeque.h"
#include "../exception/StackEmpty.h"

using namespace std;

template <typename E>
class DequeStack {
public:
    DequeStack(): deque() {}

    int size() const { return deque.size(); }
    bool empty() const { return deque.empty(); }

    const E& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("top of empty stack");
        }

        return deque.front();
    }

    void push(const E& elem) {
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
    LinkedDeque<E> deque;
};

#endif //DATA_STRUCTURE_LECTURE_DEQUESTACK_H
