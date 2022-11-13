#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREE_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREE_H


#include "LinkedBinaryTree.h"

template <typename E>
class LinkedBinarySearchTree : public LinkedBinaryTree<E> {
public:
    LinkedBinarySearchTree() : LinkedBinaryTree<E>() {}

    void addNode(E elem) {
        BinaryPosition<E> target = getTargetPosition(elem, this->getRoot());
        target.getNode()->setElem(elem);
        this->length++;
    }

    BinaryPosition<E> getTargetPosition(E newElem, BinaryPosition<E> cur) {
        BinaryNode<E> *curNode = cur.getNode();

        if (curNode->isEmpty()) {
            return cur;
        }

        if (newElem <= *cur) {
            if (curNode->getLeft() == nullptr) {
                curNode->addLeftEmptyNode();
            }
            return getTargetPosition(newElem, cur.getLeft());
        } else {
            if (curNode->getRight() == nullptr) {
                curNode->addRightEmptyNode();
            }
            return getTargetPosition(newElem, cur.getRight());
        }
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREE_H
