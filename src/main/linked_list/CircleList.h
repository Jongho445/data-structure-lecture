#ifndef DATA_STRUCTURE_LECTURE_CIRCLELIST_H
#define DATA_STRUCTURE_LECTURE_CIRCLELIST_H


#include "node/CNode.h"

class CircleList {
public:
    CircleList(): cursor(nullptr) {}
    ~CircleList() {
        while (!empty()) {
            remove();
        }
    }

    const Elem& front() const { return cursor->next->elem; }
    const Elem& back() const { return cursor->elem; }
    bool empty() const { return cursor == nullptr; }

    void advance() { cursor = cursor->next; }

    void add(const Elem& elem) {
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
    void remove() {
        CNode *targetNode = cursor->next;

        if (targetNode == cursor) {
            cursor = nullptr;
        } else {
            cursor->next = targetNode->next;
        }

        delete targetNode;
    }

    string toString() {
        string result = "[ ";
        CNode *curNode = cursor->next;

        while(true) {
            result += curNode->toString();

            if (curNode != cursor) {
                result += ", ";
            } else {
                result += "* ]";
            }

            if (curNode == cursor) {
                break;
            }

            curNode = curNode->next;
        }

        return result;
    }
private:
    CNode* cursor;
};

#endif //DATA_STRUCTURE_LECTURE_CIRCLELIST_H
