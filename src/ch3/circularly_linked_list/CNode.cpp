#include "CNode.h"

CNode::CNode(): next(nullptr) {}

string CNode::toString() {
    if (next != nullptr) {
        return "{ elem: \"" + elem
               + "\", next: " + toString(next) + " }";
    }

    return "null";
}

string CNode::toString(CNode *node) {
    string result = node->elem;

    if (result.empty()) {
        return "\"\"";
    }

    return "\"" + result + "\"";
}