#ifndef DATA_STRUCTURE_LECTURE_DNODE_H
#define DATA_STRUCTURE_LECTURE_DNODE_H


#include "string"

using namespace std;

typedef string Elem;

class DNode {
public:
    DNode(): prev(nullptr), next(nullptr) {}

    DNode(Elem value, DNode *prevNode, DNode *nextNode) {
        elem = value;

        prev = prevNode;
        next = nextNode;
    }

    string toString() {
        if (isHeader()) {
            return "{ HEADER }";
        } else if (isTrailer()) {
            return "{ TRAILER }";
        } else {
            return "{ prev: " + toString(prev)
                   + ", elem: \"" + elem
                   + "\", next: " + toString(next) + " }";
//        return "{ elem: \"" + elem
//                + ", prev: " + toString(prev)
//                + "\", next: " + toString(next) + " }";
        }
    }
    string toString(DNode *node) {
        string result = node->elem;

        if (result.empty()) {
            if (node->isHeader()) {
                return "HEADER";
            } else if (node->isTrailer()) {
                return "TRAILER";
            }
        }

        return "\"" + result + "\"";
    }
private:
    Elem elem;
    DNode* prev;
    DNode* next;

    bool isHeader() { return prev == nullptr; }
    bool isTrailer() { return next == nullptr; }

    friend class DLinkedList;
    friend class DoublyLinkedListTest;

    friend class NodeList;
    friend class Iterator;
};

#endif //DATA_STRUCTURE_LECTURE_DNODE_H
