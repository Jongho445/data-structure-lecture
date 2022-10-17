#ifndef DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H
#define DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H

#include "string"
#include "../../linked_list/doubly_linked_list/DLinkedList.h"
#include "../../exception/DequeEmpty.h"

using namespace std;

typedef string Elem;

class LinkedDeque {
public:
    LinkedDeque();
    int size() const;
    bool empty() const;

    const Elem& front() const throw(DequeEmpty);
    const Elem& back() const throw(DequeEmpty);

    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront() throw(DequeEmpty);
    void removeBack() throw(DequeEmpty);

    string toString();
private:
    DLinkedList D;
    int n;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDDEQUE_H
