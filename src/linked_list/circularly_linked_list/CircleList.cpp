#include "CircleList.h"

CircleList::CircleList(): cursor(nullptr) { }

CircleList::~CircleList() {
    while (!empty()) {
        remove();
    }
}
const Elem& CircleList::front() const {
    return cursor->next->elem;
}

const Elem& CircleList::back() const {
    return cursor->elem;
}

bool CircleList::empty() const {
    return cursor == nullptr;
}

void CircleList::advance() {
    cursor = cursor->next;
}

void CircleList::add(const Elem& elem) {
    CNode *newNode = new CNode;
    newNode->elem = elem;

    if (cursor == nullptr) {
        newNode->next = newNode;

        cursor = newNode;
    } else {
        newNode->next = cursor->next;

        cursor->next = newNode;
    }
}

void CircleList::remove() {
    CNode *targetNode = cursor->next;

    if (targetNode == cursor) {
        cursor = nullptr;
    } else {
        cursor->next = targetNode->next;
    }

    delete targetNode;
}

string CircleList::toString() {
    string result = "[ -> ";
    CNode *curNode = cursor->next;

    while(true) {
        result += curNode->toString();

        if (curNode != cursor) {
            result += " -> ";
        } else {
            result += "* -> ]";
        }

        if (curNode == cursor) {
            break;
        }

        curNode = curNode->next;
    }

    return result;
}

string CircleList::toStringStartsWithCursor() {
    string result = "[ -> ";
    CNode *curNode = cursor;

    do {
        result += curNode->toString();

        if (curNode->next != cursor) {
            if (curNode == cursor) {
                result += "* -> ";
            } else {
                result += " -> ";
            }
        } else {
            result += " -> ]";
        }

        curNode = curNode->next;

    } while (curNode != cursor);

    return result;
}
