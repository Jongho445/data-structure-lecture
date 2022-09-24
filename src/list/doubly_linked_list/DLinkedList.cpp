#include "DLinkedList.h"

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;

    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!isEmpty()) {
        removeFront();
    }

    delete header;
    delete trailer;
}

bool DLinkedList::isEmpty() const {
    return header->next == trailer;
}

void DLinkedList::add(DNode* targetNode, const Elem& elem) {
    DNode *newNode = new DNode;
    newNode->elem = elem;

    newNode->next = targetNode;
    newNode->prev = targetNode->prev;

    targetNode->prev->next = newNode;
    targetNode->prev = newNode;
}

void DLinkedList::addFront(const Elem& elem){
    add(header->next, elem);
}

void DLinkedList::addBack(const Elem& elem){
    add(trailer, elem);
}

void DLinkedList::remove(DNode* targetNode) {
    DNode* prevNode = targetNode->prev;
    DNode* nextNode = targetNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete targetNode;
}

void DLinkedList::removeFront() {
    remove(header->next);
}

void DLinkedList::removeBack() {
    remove(trailer->prev);
}

string DLinkedList::toString() {
    string result = "[ ";
    DNode *curNode = header;

    while (curNode != nullptr) {
        result += curNode->toString();

        if (curNode->next != nullptr) {
            result += " <-> ";
        } else {
            result += " ]";
        }

        curNode = curNode->next;
    }

    return result;
}
