#include "NodeList.h"

NodeList::Iterator::Iterator(DNode* initNode) {
    curNode = initNode;
}

Elem& NodeList::Iterator::operator*() {
    return curNode->elem;
}

bool NodeList::Iterator::operator==(const Iterator& targetIter) const {
    return curNode == targetIter.curNode;
}

bool NodeList::Iterator::operator!=(const Iterator& targetIter) const {
    return curNode != targetIter.curNode;
}

NodeList::Iterator& NodeList::Iterator::operator++() {
    curNode = curNode->next;

    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() {
    curNode = curNode->prev;

    return *this;
}
