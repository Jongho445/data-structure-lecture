#ifndef DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_DLINKEDLIST_H


#include "node/DoubleNode.h"

template <typename E>
class DLinkedList {
public:
    DLinkedList() {
        header = new DoubleNode<E>();
        trailer = new DoubleNode<E>();

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
    E front() const { return header->next->elem; }
    E back() const { return trailer->prev->elem; }

    void addFront(E elem) { add(header->next, elem); }
    void addBack(E elem) { add(trailer, elem); }
    void removeFront() { remove(header->next); }
    void removeBack() { remove(trailer->prev); }

    string toString() {
        string result = "[\n";
        DoubleNode<E> *curNode = header;

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
    DoubleNode<E>* header;
    DoubleNode<E>* trailer;

    friend class DoublyLinkedListTest;
protected:
    void add(DoubleNode<E> *nextNode, E elem) {
        DoubleNode<E> *prevNode = nextNode->prev;

        DoubleNode<E> *newNode = new DoubleNode<E>(elem, prevNode, nextNode);

        nextNode->prev = newNode;
        prevNode->next = newNode;
    }
    void remove(DoubleNode<E> *targetNode) {
        DoubleNode<E> *prevNode = targetNode->prev;
        DoubleNode<E> *nextNode = targetNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete targetNode;
    }
};


#endif //DATA_STRUCTURE_LECTURE_DLINKEDLIST_H
