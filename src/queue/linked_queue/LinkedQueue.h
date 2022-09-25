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
    const Elem& front() const throw(QueueEmpty);

    bool empty() const;

    void enqueue(const Elem& e);
    void dequeue() throw(QueueEmpty);
private:
    CircleList C;
    int n;
};


#endif //DATA_STRUCTURE_LECTURE_LINKEDQUEUE_H
