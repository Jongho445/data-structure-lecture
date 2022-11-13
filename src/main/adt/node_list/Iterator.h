#ifndef DATA_STRUCTURE_LECTURE_ITERATOR_H
#define DATA_STRUCTURE_LECTURE_ITERATOR_H


#include "../../linked_list/node/DoubleNode.h"

using namespace std;

template <typename E>
class Iterator {
public:
    DoubleNode<E> *curNode;

    Iterator(DoubleNode<E>* initNode) {
        curNode = initNode;
    }

    DoubleNode<E> *getCurNode() const {
        return curNode;
    }

    E operator*() const {
        return curNode->elem;
    }

    bool operator==(Iterator<E> targetIter) const {
        return curNode == targetIter.curNode;
    }

    bool operator!=(Iterator<E> targetIter) const {
        return curNode != targetIter.curNode;
    }

    Iterator<E> operator++() {
        curNode = curNode->next;

        return *this;
    }

    Iterator operator--() {
        curNode = curNode->prev;

        return *this;
    }
};

#endif //DATA_STRUCTURE_LECTURE_ITERATOR_H
