#ifndef DATA_STRUCTURE_LECTURE_BINARYNODE_H
#define DATA_STRUCTURE_LECTURE_BINARYNODE_H


template <typename E>
class BinaryNode {
private:
    typedef BinaryNode<E> Node;

    E elem;
    Node *parent;
    Node *left;
    Node *right;

    bool empty;
public:
    BinaryNode(): parent(nullptr), left(nullptr), right(nullptr), empty(true) {}
    BinaryNode(Node *parent): parent(parent), left(nullptr), right(nullptr), empty(true) {}
    BinaryNode(E elem, Node *parent): elem(elem), parent(parent), left(nullptr), right(nullptr), empty(false) {}

    void setElem(E newElem) {
        elem = newElem;
        empty = false;
    }

    void setParent(Node *node) { parent = node; }
    void setLeft(Node *node) { left = node; }
    void setRight(Node *node) { right = node; }

    bool isEmpty() { return empty; }

    E getElem() const { return elem; }
    Node *getParent() const { return parent; }
    Node *getLeft() const { return left; }
    Node *getRight() const { return right; }

    void addLeftEmptyNode() { left = new Node(this); }
    void addRightEmptyNode() { right = new Node(this); }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYNODE_H
