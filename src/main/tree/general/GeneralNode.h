#ifndef DATA_STRUCTURE_LECTURE_GENERALNODE_H
#define DATA_STRUCTURE_LECTURE_GENERALNODE_H


#include "vector"

template <typename E>
class GeneralNode {
private:
    E elem;
    GeneralNode<E> *parent;
    vector<GeneralNode<E>*> *children;
public:
    GeneralNode(): parent(nullptr), children(new vector<GeneralNode<E>*>()) {}
    GeneralNode(E elem, GeneralNode<E> *parent): elem(elem), parent(parent), children(new vector<GeneralNode<E>*>()) {}

    E getElem() const {
        return elem;
    }

    GeneralNode<E> *getParent() const {
        return parent;
    }

    vector<GeneralNode<E>*> *getChildren() const {
        return children;
    }

    GeneralNode<E> *addNode(E elem) {
        GeneralNode<E> *newNode = new GeneralNode<E>(elem, this);

        children->push_back(newNode);

        return newNode;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALNODE_H
