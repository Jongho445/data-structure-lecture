#ifndef DATA_STRUCTURE_LECTURE_DEQUESTACK_H
#define DATA_STRUCTURE_LECTURE_DEQUESTACK_H


#include "string"
#include "../../queue/linked_deque/LinkedDeque.h"
#include "../../exception/StackEmpty.h"

using namespace std;

typedef string Elem;
class DequeStack {
public:
    DequeStack();

    int size() const;
    bool empty() const;

    const Elem& top() const throw(StackEmpty);

    void push(const Elem& e);
    void pop() throw(StackEmpty);

    string toString();
private:
    LinkedDeque D;
};

#endif //DATA_STRUCTURE_LECTURE_DEQUESTACK_H
