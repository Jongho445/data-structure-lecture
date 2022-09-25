#include "Node.h"

Node::Node(): elem(""), prev(nullptr), next(nullptr) {}

Node::Node(Elem elem, Node *prev, Node *next) {
    this->elem = elem;
    this->prev = prev;
    this->next = next;
};

string Node::toString() {
    return elem;
}
