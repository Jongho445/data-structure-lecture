#include "NodeList.h"

NodeList::NodeList() {
    header = new DNode();
    trailer = new DNode();

    header->next = trailer;
    trailer->prev = header;

    length = 0;
}

int NodeList::size() const {
    return length;
}

bool NodeList::empty() const {
    return length == 0;
}

NodeList::Iterator NodeList::begin() const {
    return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const {
    return Iterator(trailer);
}

void NodeList::insert(const NodeList::Iterator& targetIter, const Elem& elem) {
    DNode *nextNode = targetIter.curNode;
    DNode *prevNode = nextNode->prev;

    DNode *newNode = new DNode(elem, prevNode, nextNode);

    nextNode->prev = newNode;
    prevNode->next = newNode;

    length++;
}

void NodeList::insertFront(const Elem& elem) {
    insert(begin(), elem);
}

void NodeList::insertBack(const Elem& elem) {
    insert(end(), elem);
}

void NodeList::erase(const Iterator& targetIter) {
    DNode *targetNode = targetIter.curNode;

    DNode *nextNode = targetNode->next;
    DNode *prevNode = targetNode->prev;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete targetNode;

    length--;
}

void NodeList::eraseFront() {
    erase(begin());
}

void NodeList::eraseBack() {
    erase(--end());
}
