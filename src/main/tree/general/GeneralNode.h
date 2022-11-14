#ifndef DATA_STRUCTURE_LECTURE_GENERALNODE_H
#define DATA_STRUCTURE_LECTURE_GENERALNODE_H


#include "vector"

template <typename E>
class GeneralNode {
private:
    typedef GeneralNode<E> Node;

    E elem;
    Node *parent;
    vector<Node*> *children;
public:
    GeneralNode(): parent(nullptr), children(new vector<Node*>()) {}
    GeneralNode(E elem, Node *parent): elem(elem), parent(parent), children(new vector<Node*>()) {}

    E getElem() const {
        return elem;
    }

    Node *getParent() const {
        return parent;
    }

    vector<Node*> *getChildren() const {
        return children;
    }

    Node *addNode(E elem) {
        Node *newNode = new Node(elem, this);

        children->push_back(newNode);

        return newNode;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALNODE_H
