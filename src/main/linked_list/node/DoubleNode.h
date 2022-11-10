#ifndef DATA_STRUCTURE_LECTURE_DOUBLENODE_H
#define DATA_STRUCTURE_LECTURE_DOUBLENODE_H


#include "string"

using namespace std;

template <typename E>
class DoubleNode {
public:

    E elem;
    DoubleNode* prev;
    DoubleNode* next;

    bool isHeader() { return prev == nullptr; }
    bool isTrailer() { return next == nullptr; }

    DoubleNode(): prev(nullptr), next(nullptr) {}
    DoubleNode(E value, DoubleNode *prevNode, DoubleNode *nextNode) {
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
    string toString(DoubleNode *node) {
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
};

#endif //DATA_STRUCTURE_LECTURE_DOUBLENODE_H
