#ifndef DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H
#define DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H


#include "string"
#include "../../exception/QueueEmpty.h"
#include "../../linked_list/circularly_linked_list/CircleList.h"

using namespace std;

typedef string Elem;

class LinkedQueue {
public:
    LinkedQueue();

    int size() const;
    bool empty() const;

    const Elem& front() const throw(QueueEmpty);

    void enqueue(const Elem& elem);
    void dequeue() throw(QueueEmpty);

    string toString();
private:
    CircleList linkedList;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H
