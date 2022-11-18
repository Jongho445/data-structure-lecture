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
public:
    BinaryNode(): parent(nullptr), left(nullptr), right(nullptr) {}
    BinaryNode(Node *parent): parent(parent), left(nullptr), right(nullptr) {}

    E getElem() const { return elem; }
    Node *getParent() const { return parent; }
    Node *getLeft() const { return left; }
    Node *getRight() const { return right; }

    void setElem(E newElem) { elem = newElem; }
    void setParent(Node *node) { parent = node; }
    void setLeft(Node *node) { left = node; }
    void setRight(Node *node) { right = node; }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYNODE_H
