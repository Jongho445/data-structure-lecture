#include "Node.h"

Node::Node(): elem(""), prev(nullptr), next(nullptr) {}

Node::Node(Elem value, Node *prevNode, Node *nextNode) {
    elem = value;

    prev = prevNode;
    next = nextNode;
};

string Node::toString() {
    return elem;
}
