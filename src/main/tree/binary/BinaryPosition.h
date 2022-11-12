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

    const E &operator*() const { return node->getElem(); }

    bool isRoot() const { return node->getParent() == nullptr; }
    bool isExternal() const { return node->getLeft() == nullptr && node->getRight() == nullptr; }

    bool isEmpty() { return node->isEmpty(); }

    BinaryNode<E> *getNode() { return node; }

    BinaryPosition *getParent() {
        BinaryNode<E> *parentNode = node->getParent();
        if (parentNode == nullptr) {
            return nullptr;
        }

        return new BinaryPosition<E>(parentNode);
    }

    BinaryPosition *getLeft() {
        BinaryNode<E> *leftNode = node->getLeft();
        if (leftNode == nullptr) {
            return nullptr;
        }

        return new BinaryPosition<E>(leftNode);
    }

    BinaryPosition *getRight() {
        BinaryNode<E> *rightNode = node->getRight();
        if (rightNode == nullptr) {
            return nullptr;
        }

        return new BinaryPosition<E>(rightNode);
    }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYPOSITION_H
