#ifndef DATA_STRUCTURE_LECTURE_BINARYNODE_H
#define DATA_STRUCTURE_LECTURE_BINARYNODE_H


template <typename E>
class BinaryNode {
private:
    E elem;
    BinaryNode<E> *parent;
    BinaryNode<E> *left;
    BinaryNode<E> *right;

    bool empty;
public:
    BinaryNode(): parent(nullptr), left(nullptr), right(nullptr), empty(true) {}
    BinaryNode(BinaryNode<E> *parent): parent(parent), left(nullptr), right(nullptr), empty(true) {}
    BinaryNode(E elem, BinaryNode<E> *parent): elem(elem), parent(parent), left(nullptr), right(nullptr), empty(false) {}

    void setElem(E newElem) {
        elem = newElem;
        empty = false;
    }

    void setParent(BinaryNode<E> *node) { parent = node; }
    void setLeft(BinaryNode<E> *node) { left = node; }
    void setRight(BinaryNode<E> *node) { right = node; }

    bool isEmpty() { return empty; }

    E getElem() const { return elem; }
    BinaryNode<E> *getParent() const { return parent; }
    BinaryNode<E> *getLeft() const { return left; }
    BinaryNode<E> *getRight() const { return right; }

    void addLeftEmptyNode() { left = new BinaryNode<E>(this); }
    void addRightEmptyNode() { right = new BinaryNode<E>(this); }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYNODE_H
