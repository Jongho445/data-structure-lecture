#ifndef DATA_STRUCTURE_LECTURE_SINGLENODE_H
#define DATA_STRUCTURE_LECTURE_SINGLENODE_H


#include "string"

using namespace std;

template <typename E>
class SingleNode {
public:

    E elem;
    SingleNode<E> *next;

    SingleNode(): next(nullptr) {}

    string toString() {
        if (next != nullptr) {
            return "{ elem: \"" + elem
                   + "\", next: " + toString(next) + " }";
        }

        return "null";
    }
    string toString(SingleNode<E> *node) {
        string result = node->elem;

        if (result.empty()) {
            return "\"\"";
        }

        return "\"" + result + "\"";
    }
};


#endif //DATA_STRUCTURE_LECTURE_SINGLENODE_H
