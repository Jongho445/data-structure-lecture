#include "NodeList.h"

NodeList::NodeList() {
    header = new Node;
    trailer = new Node;

    header->next = trailer;
    trailer->prev = header;

    n = 0;
}

int NodeList::size() const {
    return n;
}

bool NodeList::empty() const {
    return (n == 0);
}

NodeList::Iterator NodeList::begin() const {
    return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const {
    return Iterator(trailer);
}

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
    Node* w = p.v; // p’s node
    Node* u = w->prev; // p’s predecessor
    Node* v = new Node; // new node to insert
    v->elem = e;
    v->next = w; w->prev = v; // link in v before w
    v->prev = u; u->next = v; // link in v after u
    n++;
}

void NodeList::insertFront(const Elem& e) {
    insert(begin(), e);
}

void NodeList::insertBack(const Elem& e) {
    insert(end(), e);
}

void NodeList::erase(const Iterator& p) {
    Node* v = p.v; // node to remove
    Node* w = v->next; // successor
    Node* u = v->prev; // predecessor
    u->next = w; w->prev = u; // unlink p
    delete v; // delete this node
    n--; // one fewer element
}

void NodeList::eraseFront() {
    erase(begin());
}

void NodeList::eraseBack() {
    erase(--end());
}
