#ifndef DATA_STRUCTURE_LECTURE_ARRAYSTACK_H
#define DATA_STRUCTURE_LECTURE_ARRAYSTACK_H

#include "../../exception/StackEmpty.h"
#include "../../exception/StackFull.h"

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    ArrayStack(int cap = DEF_CAPACITY) {
        S = new E[cap];
        capacity = cap;
        t = -1;
    };

    int size() const {
        return (t + 1);
    };

    bool empty() const {
        return (t < 0);
    };

    const E& top() const throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Top of empty stack");
        }

        return S[t];
    };

    void push(const E& e) throw(StackFull) {
        if (size() == capacity) {
            throw StackFull("Push to full stack");
        }

        S[++t] = e;
    };

    void pop() throw(StackEmpty) {
        if (empty()) {
            throw StackEmpty("Pop from empty stack");
        }

        --t;
    };
private:
    E* S;
    int capacity;
    int t;
};

#endif //DATA_STRUCTURE_LECTURE_ARRAYSTACK_H
