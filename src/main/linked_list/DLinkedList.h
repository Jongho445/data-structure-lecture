#ifndef DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_DLINKEDLIST_H


#include "node/DNode.h"

class DLinkedList {
public:
    DLinkedList() {
        header = new DNode();
        trailer = new DNode();

        header->next = trailer;
        trailer->prev = header;
    }

    ~DLinkedList() {
        while (!empty()) {
            removeFront();
        }

        delete header;
        delete trailer;
    }

    bool empty() const { return header->next == trailer; }
    const Elem& front() const { return header->next->elem; }
    const Elem& back() const { return trailer->prev->elem; }

    void addFront(const Elem &elem) { add(header->next, elem); }
    void addBack(const Elem &elem) { add(trailer, elem); }
    void removeFront() { remove(header->next); }
    void removeBack() { remove(trailer->prev); }

    string toString() {
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
private:
    DNode* header;
    DNode* trailer;

    friend class DoublyLinkedListTest;
protected:
    void add(DNode *nextNode, const Elem &elem) {
        DNode *prevNode = nextNode->prev;

        DNode *newNode = new DNode(elem, prevNode, nextNode);

        nextNode->prev = newNode;
        prevNode->next = newNode;
    }
    void remove(DNode *targetNode) {
        DNode *prevNode = targetNode->prev;
        DNode *nextNode = targetNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete targetNode;
    }
};


#endif //DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
