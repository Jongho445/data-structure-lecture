#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H


#include "vector"
#include "BinaryNode.h"
#include "BinaryPosition.h"

template <typename E>
class LinkedBinaryTree {
protected:
    BinaryNode<E> *root;
    int length;
public:
    LinkedBinaryTree(): root(new BinaryNode<E>(nullptr)), length(0) {}
    ~LinkedBinaryTree() {
        vector<BinaryPosition<int>> *positions = getPositions(Traversal::PREORDER);

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

    void printTree(Traversal traversal) {
        vector<BinaryPosition<E>> *positions = getPositions(traversal);

        typename vector<BinaryPosition<E>>::iterator iter;
        for (iter = positions->begin(); iter != positions->end(); ++iter) {
            cout << **iter;
            cout << " ";
        }
        cout << endl;

        delete positions;
    }

    vector<BinaryPosition<E>> *getPositions(Traversal traversal) {
        vector<BinaryPosition<E>> *positions = new vector<BinaryPosition<E>>();
        switch (traversal) {
            case PREORDER: pushPreorder(getRoot(), positions); break;
            case POSTORDER: pushPostorder(getRoot(), positions); break;
            case INORDER: pushInorder(getRoot(), positions); break;
        }

        return positions;
    }
private:
    void pushPreorder(BinaryPosition<E> target, vector<BinaryPosition<E>> *positions) {
        positions->push_back(target);

        if (target.getNode()->getLeft() != nullptr) {
            pushPreorder(target.getLeft(), positions);
        }

        if (target.getNode()->getRight() != nullptr) {
            pushPreorder(target.getRight(), positions);
        }
    }

    void pushPostorder(BinaryPosition<E> target, vector<BinaryPosition<E>> *positions) {
        if (target.getNode()->getLeft() != nullptr) {
            pushPostorder(target.getLeft(), positions);
        }

        if (target.getNode()->getRight() != nullptr) {
            pushPostorder(target.getRight(), positions);
        }

        positions->push_back(target);
    }

    void pushInorder(BinaryPosition<E> target, vector<BinaryPosition<E>> *positions) {
        if (target.getNode()->getLeft() != nullptr) {
            pushInorder(target.getLeft(), positions);
        }

        positions->push_back(target);

        if (target.getNode()->getRight() != nullptr) {
            pushInorder(target.getRight(), positions);
        }
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYTREE_H
