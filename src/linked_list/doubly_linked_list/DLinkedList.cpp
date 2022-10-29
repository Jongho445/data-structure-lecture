#include "DLinkedList.h"

DLinkedList::DLinkedList() {
    header = new DNode();
    trailer = new DNode();

    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) {
        removeFront();
    }

    delete header;
    delete trailer;
}

bool DLinkedList::empty() const { return header->next == trailer; }
const Elem& DLinkedList::front() const { return header->next->elem; }
const Elem& DLinkedList::back() const { return trailer->prev->elem; }

void DLinkedList::add(DNode *nextNode, const Elem &elem) {
    DNode *prevNode = nextNode->prev;

    DNode *newNode = new DNode(elem, prevNode, nextNode);

    nextNode->prev = newNode;
    prevNode->next = newNode;
}

void DLinkedList::remove(DNode *targetNode) {
    DNode *prevNode = targetNode->prev;
    DNode *nextNode = targetNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete targetNode;
}

void DLinkedList::addFront(const Elem &elem){ add(header->next, elem); }
void DLinkedList::addBack(const Elem &elem){ add(trailer, elem); }

void DLinkedList::removeFront() { remove(header->next); }
void DLinkedList::removeBack() { remove(trailer->prev); }

string DLinkedList::toString() {
    string result = "[\n";
    DNode *curNode = header;

    while (curNode != nullptr) {
        string elem = curNode->toString();

        if (elem == "{ HEADER }") {
            curNode = curNode->next;
            continue;
        }

        if (elem == "{ TRAILER }") {
            result += "\n]";
            break;
        }

        result += "    ";
        result += elem;

        if (curNode->next->toString() != "{ TRAILER }") {
            result += ",\n";
        }

        curNode = curNode->next;
    }

    return result;
}

string DLinkedList::toStringInclusiveOfHeadOrTail() {
    string result = "[ ";
    DNode *curNode = header;

    while (curNode != nullptr) {
        string elem = curNode->toString();
        result += elem;

        if (curNode->next != nullptr) {
            result += ", ";
        } else {
            result += " ]";
        }

        curNode = curNode->next;
    }

    return result;
}
