#ifndef DATA_STRUCTURE_LECTURE_BINARYPOSITION_H
#define DATA_STRUCTURE_LECTURE_BINARYPOSITION_H


#include "BinaryNode.h"

template <typename E>
class BinaryPosition {
private:
    BinaryNode<E> *node;
public:
    BinaryPosition(): node(nullptr) {}
    BinaryPosition(BinaryNode<E> *node): node(node) {}

    E operator*() const { return node->getElem(); }

    bool isRoot() const { return node->getParent() == nullptr; }
    bool isExternal() const { return node->getLeft() == nullptr && node->getRight() == nullptr; }

    BinaryNode<E> *getNode() { return node; }

    BinaryPosition getParent() { return BinaryPosition<E>(node->getParent()); }
    BinaryPosition getLeft() { return BinaryPosition<E>(node->getLeft()); }
    BinaryPosition getRight() { return BinaryPosition<E>(node->getRight()); }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYPOSITION_H
