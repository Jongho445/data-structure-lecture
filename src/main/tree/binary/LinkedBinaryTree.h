#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H


#include "BinaryNode.h"
#include "BinaryPosition.h"

template <typename E>
class LinkedBinaryTree {
public:
    LinkedBinaryTree(): root(new BinaryNode<E>(nullptr)), length(0) {}

    int getLength() { return length; }
    bool isEmpty() { return length == 0; }
    BinaryPosition<E> *getRoot() { return new BinaryPosition<E>(root); }

    BinaryPosition<E> *removeAboveExternal(BinaryPosition<E> *leaf) {
        if (!leaf->isExternal()) {
            return nullptr;
        }

        BinaryNode<E>* target = leaf->getNode();
        BinaryNode<E>* parent = target->getParent();
        BinaryNode<E>* sibling = (target == parent->getLeft() ? parent->getRight() : parent->getLeft());

        if (parent == root) {
            root = sibling;
            sibling->setParent(nullptr);
        } else {
            BinaryNode<E>* grandParent = parent->getParent();
            if (parent == grandParent->getLeft()) {
                grandParent->setLeft(sibling);
            } else {
                grandParent->setRight(sibling);
            }
            sibling->setParent(grandParent);
        }

        delete target;
        delete parent;

        length -= 2;

        return new BinaryPosition<E>(sibling);
    }

    void addNode(E elem) {
        BinaryPosition<E> *target = getTargetPosition(elem, getRoot());
        target->getNode()->setElem(elem);
        length++;
    }

    BinaryPosition<E> *getTargetPosition(E newElem, BinaryPosition<E> *cur) {
        if (cur->isEmpty()) {
            return cur;
        }

        if (newElem <= **cur) {
            if (cur->getLeft() == nullptr) {
                cur->getNode()->addLeftEmptyNode();
            }
            return getTargetPosition(newElem, cur->getLeft());
        } else {
            if (cur->getRight() == nullptr) {
                cur->getNode()->addRightEmptyNode();
            }
            return getTargetPosition(newElem, cur->getRight());
        }
    }

    void printTree(BinaryPosition<E> *position) {
        if (position == nullptr) {
            return;
        }

        printTree(position->getLeft());
        cout << **position;
        cout << " ";
        printTree(position->getRight());
    }

    NodeList<BinaryPosition<E>*> *getPositions() {
        NodeList<BinaryPosition<E> *> *positions = new NodeList<BinaryPosition<E> *>();

        pushPreorder(root, positions);

        return positions;
    }

    void pushPreorder(BinaryNode<E> *node, NodeList<BinaryPosition<E>*> *positions) {
        positions->insertBack(new BinaryPosition<E>(node));

        if (node->getLeft() != nullptr) {
            pushPreorder(node->getLeft(), positions);
        }

        if (node->getRight() != nullptr) {
            pushPreorder(node->getRight(), positions);
        }
    }
private:
    BinaryNode<E> *root;
    int length;
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
