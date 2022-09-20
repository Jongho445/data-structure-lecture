#include "DNode.h"

DNode::DNode(): prev(nullptr), next(nullptr) {}

string DNode::toString() {
    if (prev != nullptr && next != nullptr) {
        return "{ prev: " + toString(prev)
               + ", elem: \"" + elem
               + "\", next: " + toString(next) + " }";
    }

    return "null";
}

string DNode::toString(DNode *node) {
    string result = node->elem;

    if (result.empty()) {
        return "\"\"";
    }

    return "\"" + result + "\"";
}