#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H


#include "vector"
#include "BinaryNode.h"
#include "BinaryPosition.h"

template <typename E>
class LinkedBinaryTree {
private:
    BinaryNode<E> *root;
    int length;
public:
    LinkedBinaryTree(): root(new BinaryNode<E>(nullptr)), length(0) {}
    ~LinkedBinaryTree() {
        vector<BinaryPosition<int>> *positions = getPositions();

        typename vector<BinaryPosition<E>>::iterator iter;
        for (iter = positions->begin(); iter != positions->end(); ++iter) {
            BinaryNode<E> *node = (*iter).getNode();
            delete node;
        }
    }

    int getLength() { return length; }
    bool isEmpty() { return length == 0; }
    BinaryPosition<E> getRoot() { return BinaryPosition<E>(root); }

    BinaryPosition<E> removeAboveExternal(BinaryPosition<E> leaf) {
        if (!leaf.isExternal()) {
            return BinaryPosition<E>(nullptr);
        }

        BinaryNode<E> *target = leaf.getNode();
        BinaryNode<E> *parent = target->getParent();
        BinaryNode<E> *sibling = (target == parent->getLeft() ? parent->getRight() : parent->getLeft());

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

        return BinaryPosition<E>(sibling);
    }

    void addNode(E elem) {
        BinaryPosition<E> target = getTargetPosition(elem, getRoot());
        target.getNode()->setElem(elem);
        length++;
    }

    BinaryPosition<E> getTargetPosition(E newElem, BinaryPosition<E> cur) {
        if (cur.isEmpty()) {
            return cur;
        }

        if (newElem <= *cur) {
            if (cur.getLeft().getNode() == nullptr) {
                cur.getNode()->addLeftEmptyNode();
            }
            return getTargetPosition(newElem, cur.getLeft());
        } else {
            if (cur.getRight().getNode() == nullptr) {
                cur.getNode()->addRightEmptyNode();
            }
            return getTargetPosition(newElem, cur.getRight());
        }
    }

    void printTree(BinaryPosition<E> position) {
        if (position.getNode() == nullptr) {
            return;
        }

        printTree(position.getLeft());
        cout << *position;
        cout << " ";
        printTree(position.getRight());
    }

    vector<BinaryPosition<E>> *getPositions() {
        vector<BinaryPosition<E>> *positions = new vector<BinaryPosition<E>>();
        pushPreorder(root, positions);

        return positions;
    }

    void pushPreorder(BinaryNode<E> *node, vector<BinaryPosition<E>> *positions) {
        positions->push_back(BinaryPosition<E>(node));

        if (node->getLeft() != nullptr) {
            pushPreorder(node->getLeft(), positions);
        }

        if (node->getRight() != nullptr) {
            pushPreorder(node->getRight(), positions);
        }
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
