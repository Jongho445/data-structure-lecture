#include "NodeList.h"

NodeList::NodeList() {
    header = new Node();
    trailer = new Node();

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
    Node *nextNode = targetIter.curNode;
    Node *prevNode = nextNode->prev;

    Node *newNode = new Node(elem, prevNode, nextNode);

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
    Node *targetNode = targetIter.curNode;

    Node *nextNode = targetNode->next;
    Node *prevNode = targetNode->prev;

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
