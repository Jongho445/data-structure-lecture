#ifndef DATA_STRUCTURE_LECTURE_BINARYPOSITION_H
#define DATA_STRUCTURE_LECTURE_BINARYPOSITION_H


#include "BinaryNode.h"

template <typename E>
class BinaryPosition {
private:
    typedef BinaryNode<E> Node;
    typedef BinaryPosition<E> Position;

    Node *node;
public:
    BinaryPosition(): node(nullptr) {}
    BinaryPosition(Node *node): node(node) {}

    Node *getNode() { return node; }

    E operator*() const { return node->getElem(); }

    bool operator==(Position pos) { return node == pos.getNode(); }
    bool operator!=(Position pos) { return node != pos.getNode(); }

    bool isRoot() const { return node->getParent() == nullptr; }
    bool isExternal() const { return node->getLeft() == nullptr && node->getRight() == nullptr; }
    bool isInternal() const { return !isExternal(); }

    Position getParent() { return Position(node->getParent()); }
    Position getLeft() { return Position(node->getLeft()); }
    Position getRight() { return Position(node->getRight()); }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYPOSITION_H
