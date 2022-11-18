#ifndef DATA_STRUCTURE_LECTURE_FULLBINARYTREE_H
#define DATA_STRUCTURE_LECTURE_FULLBINARYTREE_H


#include "vector"
#include "LinkedBinaryTree.h"

using namespace std;

template <typename E>
class FullBinaryTree : public LinkedBinaryTree<E> {
private:
    typedef BinaryNode<E> Node;
    typedef BinaryPosition<E> Position;
    typedef typename vector<BinaryPosition<E>>::iterator Iterator;
public:
    void expandExternal(Position pos) {
        Node *node = pos.getNode();

        node->setLeft(new Node(node));
        node->setRight(new Node(node));

        this->length += 2;
    }

    Position removeAboveExternal(Position leaf) {
        if (!leaf.isExternal()) {
            return Position(nullptr);
        }

        Node *target = leaf.getNode();
        Node *parent = target->getParent();
        Node *sibling = (target == parent->getLeft() ? parent->getRight() : parent->getLeft());

        if (parent == this->root) {
            this->root = sibling;
            sibling->setParent(nullptr);
        } else {
            Node *grandParent = parent->getParent();

            if (parent == grandParent->getLeft()) {
                grandParent->setLeft(sibling);
            } else {
                grandParent->setRight(sibling);
            }

            sibling->setParent(grandParent);
        }

        delete target;
        delete parent;

        this->length -= 2;

        return Position(sibling);
    }
};

#endif //DATA_STRUCTURE_LECTURE_FULLBINARYTREE_H
