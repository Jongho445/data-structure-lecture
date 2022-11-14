#ifndef DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
#define DATA_STRUCTURE_LECTURE_GENERALPOSITION_H

#include "vector"
#include "GeneralNode.h"

template <typename E>
class GeneralPosition {
private:
    typedef GeneralNode<E> Node;
    typedef GeneralPosition<E> Position;

    Node *node;
public:
    GeneralPosition(): node(nullptr) {}
    GeneralPosition(Node *node): node(node) {}

    E operator*() const { return node->getElem(); };
    Node *getNode() { return node; };
    Position getParent() const { return Position(node->getParent()); };

    vector<Position> *getChildren() const {
        vector<Position> *positions = new vector<Position>();

        vector<Node*> *children = node->getChildren();
        typename vector<Node*>::iterator iter;
        for (iter = children->begin(); iter != children->end(); ++iter) {
            positions->push_back(Position(*iter));
        }

        return positions;
    };

    bool isRoot() const { return node->getParent() == nullptr; };
    bool isExternal() const { return node->getChildren()->size() <= 0; };
};

#endif //DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
