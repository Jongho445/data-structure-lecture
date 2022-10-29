#ifndef DATA_STRUCTURE_LECTURE_ARRAYSTACK_H
#define DATA_STRUCTURE_LECTURE_ARRAYSTACK_H

#include "../../exception/StackEmpty.h"
#include "../../exception/StackFull.h"

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    ArrayStack(int cap = DEF_CAPACITY) {
        arr = new E[cap];
        capacity = cap;
        length = -1;
    };

    int size() const { return length + 1; };
    bool empty() const { return length < 0; };

    const E& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Top of empty stack");
        }

        return arr[length];
    };

    void push(const E& elem) throw(StackFull) {
        if (size() == capacity) {
            throw StackFull("Push to full stack");
        }

        arr[++length] = elem;
    };

    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Pop from empty stack");
        }

        --length;
    };

private:
    E* arr;
    int capacity;
    int length;
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYSTACK_H
