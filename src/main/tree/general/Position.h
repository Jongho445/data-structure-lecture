#ifndef DATA_STRUCTURE_LECTURE_POSITION_H
#define DATA_STRUCTURE_LECTURE_POSITION_H

#include "../../adt/node_list/NodeList.h"

using namespace std;

template <typename E>
class Position {
private:
    E elem;
    Position *parent;
    NodeList<Position<E>*> *children;
public:
    Position() : parent(nullptr), children(nullptr) {}

    Position(E elem, Position<E> *parent) : elem(elem), parent(parent) {
        this->children = new NodeList<Position<E>*>();
    }

    E operator*() const { return elem; };
    Position<E> *getParent() const { return parent; };
    NodeList<Position<E>*> *getChildren() const { return children; };

    bool isRoot() const { return parent == nullptr; };
    bool isExternal() const { return children->size() <= 0; };
};

#endif //DATA_STRUCTURE_LECTURE_POSITION_H
