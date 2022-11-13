#ifndef DATA_STRUCTURE_LECTURE_SLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_SLINKEDLIST_H


#include "node/SingleNode.h"

template <typename E>
class SLinkedList {
public:
    SLinkedList(): head(nullptr) { };

    ~SLinkedList() {
        while (!empty()) {
            removeFront();
        }
    };

    bool empty() const { return head == nullptr; };
    E front() const { return head->elem; };

    void addFront(E elem) {
        SingleNode<E>* newNode = new SingleNode<E>;

        newNode->elem = elem;
        newNode->next = head;

        head = newNode;
    };

    void removeFront() {
        SingleNode<E>* targetNode = head;

        head = targetNode->next;

        delete targetNode;
    };

    string toString() {
        string result = "[ ";
        SingleNode<E> *curNode = head ? head : nullptr;

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
private:
    SingleNode<E>* head;
};

#endif //DATA_STRUCTURE_LECTURE_SLINKEDLIST_H
