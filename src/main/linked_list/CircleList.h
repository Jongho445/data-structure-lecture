#ifndef DATA_STRUCTURE_LECTURE_CIRCLELIST_H
#define DATA_STRUCTURE_LECTURE_CIRCLELIST_H


#include "node/SingleNode.h"

template <typename E>
class CircleList {
public:
    CircleList(): cursor(nullptr) {}
    ~CircleList() {
        while (!empty()) {
            remove();
        }
    }

    E front() const { return cursor->next->elem; }
    E back() const { return cursor->elem; }
    bool empty() const { return cursor == nullptr; }

    void advance() { cursor = cursor->next; }

    void add(E elem) {
        SingleNode<E> *newNode = new SingleNode<E>;
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
        SingleNode<E> *targetNode = cursor->next;

        if (targetNode == cursor) {
            cursor = nullptr;
        } else {
            cursor->next = targetNode->next;
        }

        delete targetNode;
    }

    string toString() {
        string result = "[ ";
        SingleNode<E> *curNode = cursor->next;

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
    SingleNode<E>* cursor;
};

#endif //DATA_STRUCTURE_LECTURE_CIRCLELIST_H
