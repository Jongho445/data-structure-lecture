#include "StringLinkedList.h"

StringLinkedList::StringLinkedList(): head(nullptr) { }

StringLinkedList::~StringLinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
}

bool StringLinkedList::isEmpty() const {
    return head == nullptr;
}

void StringLinkedList::addFront(const string& elem) {
    StringNode* newNode = new StringNode;
    newNode->elem = elem;
    newNode->next = head;
    head = newNode;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

// DIY
string StringLinkedList::toString() {
    string result = "[ ";
    StringNode *curNode = head ? head : nullptr;

    while (curNode != nullptr) {
        result += curNode->elem;

        if (curNode->next != nullptr) {
            result += ", ";
        } else {
            result += " ]";
        }

        curNode = curNode->next;
    }

    return result;
}
