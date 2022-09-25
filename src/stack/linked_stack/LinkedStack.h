#ifndef DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
#define DATA_STRUCTURE_LECTURE_LINKEDSTACK_H


#include "string"
#include "../../exception/StackEmpty.h"
#include "../../list/singly_linked_list/SLinkedList.h"

using namespace std;

typedef string Elem;

class LinkedStack {
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const Elem& top() const throw(StackEmpty);
    void push(const Elem& e);
    void pop() throw(StackEmpty);
private:
    SLinkedList<Elem> S;
    int n;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDSTACK_H
