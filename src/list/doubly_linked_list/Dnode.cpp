#include "DNode.h"

DNode::DNode(): prev(nullptr), next(nullptr) {}

string DNode::toString() {
    if (isHeader()) {
        return "{ HEADER }";
    } else if (isTrailer()) {
        return "{ TRAILER }";
    } else {
        return "{ prev: " + toString(prev)
               + ", elem: \"" + elem
               + "\", next: " + toString(next) + " }";
    }
}

string DNode::toString(DNode *node) {
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

bool DNode::isHeader() {
    return prev == nullptr;
}

bool DNode::isTrailer() {
    return next == nullptr;
}
