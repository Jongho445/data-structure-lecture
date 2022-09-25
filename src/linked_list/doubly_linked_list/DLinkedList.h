#ifndef DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_DLINKEDLIST_H


#include "DNode.h"

class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();

    bool empty() const;

    void addFront(const Elem &elem);
    void addBack(const Elem &elem);
    void removeFront();
    void removeBack();

    string toString();
private:
    DNode* header;
    DNode* trailer;

    friend class DoublyLinkedListTest;
protected:
    void add(DNode *nextNode, const Elem &elem);
    void remove(DNode *targetNode);
};


#endif //DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
