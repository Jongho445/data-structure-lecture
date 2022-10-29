#ifndef DATA_STRUCTURE_LECTURE_ITERATOR_H
#define DATA_STRUCTURE_LECTURE_ITERATOR_H


#include "string"
#include "../../linked_list/node/DNode.h"

using namespace std;

typedef string Elem;

class Iterator {
public:
    Iterator(DNode* initNode) {
        curNode = initNode;
    }

    Elem &operator*() { return curNode->elem; }

    bool operator==(const Iterator& targetIter) const { return curNode == targetIter.curNode; }
    bool operator!=(const Iterator& targetIter) const { return curNode != targetIter.curNode; }

    Iterator &operator++() {
        curNode = curNode->next;

        return *this;
    }

    Iterator &operator--() {
        curNode = curNode->prev;

        return *this;
    }

    friend class NodeList;
private:
    DNode *curNode;
};

#endif //DATA_STRUCTURE_LECTURE_ITERATOR_H
