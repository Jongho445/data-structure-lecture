#ifndef DATA_STRUCTURE_LECTURE_NODELIST_H
#define DATA_STRUCTURE_LECTURE_NODELIST_H


#include "string"
#include "../../linked_list/node/DNode.h"
#include "Iterator.h"

using namespace std;

typedef string Elem;

class NodeList {
public:
    NodeList() {
        header = new DNode();
        trailer = new DNode();

        header->next = trailer;
        trailer->prev = header;

        length = 0;
    }

    int size() const { return length; }
    bool empty() const { return length == 0; }

    Iterator begin() const { return Iterator(header->next); }
    Iterator end() const { return Iterator(trailer); }

    void insert(const Iterator& targetIter, const Elem& elem) {
        DNode *nextNode = targetIter.curNode;
        DNode *prevNode = nextNode->prev;

        DNode *newNode = new DNode(elem, prevNode, nextNode);

        nextNode->prev = newNode;
        prevNode->next = newNode;

        length++;
    }

    void erase(const Iterator& targetIter) {
        DNode *targetNode = targetIter.curNode;

        DNode *nextNode = targetNode->next;
        DNode *prevNode = targetNode->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete targetNode;

        length--;
    }

    void insertFront(const Elem& elem) { insert(begin(), elem); }
    void insertBack(const Elem& elem) { insert(end(), elem); }

    void eraseFront() { erase(begin()); }
    void eraseBack() { erase(--end()); }

private:
    int length;

    DNode *header;
    DNode *trailer;
};


#endif //DATA_STRUCTURE_LECTURE_NODELIST_H
