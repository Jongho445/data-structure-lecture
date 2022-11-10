#ifndef DATA_STRUCTURE_LECTURE_NODELIST_H
#define DATA_STRUCTURE_LECTURE_NODELIST_H


#include "string"
#include "../../linked_list/node/DoubleNode.h"
#include "Iterator.h"

using namespace std;

template <typename E>
class NodeList {
public:
    NodeList() {
        header = new DoubleNode<E>();
        trailer = new DoubleNode<E>();

        header->next = trailer;
        trailer->prev = header;

        length = 0;
    }

    int size() const { return length; }
    bool empty() const { return length == 0; }

    E getFront() { return header->next->elem; }
    E getBack() { return trailer->prev->elem; }

    Iterator<E> begin() const { return Iterator<E>(header->next); }
    Iterator<E> end() const { return Iterator<E>(trailer); }

    void insert(const Iterator<E>& targetIter, const E& elem) {
        DoubleNode<E> *nextNode = targetIter.getCurNode();
        DoubleNode<E> *prevNode = nextNode->prev;

        DoubleNode<E> *newNode = new DoubleNode<E>(elem, prevNode, nextNode);

        nextNode->prev = newNode;
        prevNode->next = newNode;

        length++;
    }

    void erase(const Iterator<E>& targetIter) {
        DoubleNode<E> *targetNode = targetIter.getCurNode();

        DoubleNode<E> *nextNode = targetNode->next;
        DoubleNode<E> *prevNode = targetNode->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete targetNode;

        length--;
    }

    void insertFront(const E& elem) { insert(begin(), elem); }
    void insertBack(const E& elem) { insert(end(), elem); }

    void eraseFront() { erase(begin()); }
    void eraseBack() { erase(--end()); }

private:
    int length;

    DoubleNode<E> *header;
    DoubleNode<E> *trailer;
};


#endif //DATA_STRUCTURE_LECTURE_NODELIST_H
