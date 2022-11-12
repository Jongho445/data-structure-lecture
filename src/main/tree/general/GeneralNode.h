#ifndef DATA_STRUCTURE_LECTURE_GENERALNODE_H
#define DATA_STRUCTURE_LECTURE_GENERALNODE_H


#include "../../adt/node_list/NodeList.h"

template <typename E>
class GeneralNode {
private:
    E elem;
    GeneralNode<E> *parent;
    NodeList<GeneralNode<E>*> *children;
public:
    GeneralNode(): parent(nullptr), children(new NodeList<GeneralNode<E>*>()) {}
    GeneralNode(E elem, GeneralNode<E> *parent): elem(elem), parent(parent), children(new NodeList<GeneralNode<E>*>()) {}

    const E &getElem() const {
        return elem;
    }

    GeneralNode<E> *getParent() const {
        return parent;
    }

    NodeList<GeneralNode<E>*> *getChildren() const {
        return children;
    }

    GeneralNode<E> *addNode(E elem) {
        GeneralNode<E> *newNode = new GeneralNode<E>(elem, this);

        children->insertBack(newNode);

        return newNode;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALNODE_H
