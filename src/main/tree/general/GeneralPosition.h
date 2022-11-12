#ifndef DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
#define DATA_STRUCTURE_LECTURE_GENERALPOSITION_H

#include "GeneralNode.h"
#include "../../adt/node_list/NodeList.h"

template <typename E>
class GeneralPosition {
private:
    GeneralNode<E> *node;
    NodeList<GeneralPosition<E>*> *childPositions;
public:
    GeneralPosition() : node(nullptr), childPositions(new NodeList<GeneralPosition<E>*>()) {}
    GeneralPosition(GeneralNode<E> *node): node(node) {
        childPositions = new NodeList<GeneralPosition<E>*>();
        
        NodeList<GeneralNode<E>*> *children = node->getChildren();
        for (Iterator<GeneralNode<E>*> iter = children->begin(); iter != children->end(); ++iter) {
            GeneralPosition<E> *newPosition = new GeneralPosition<E>(*iter);
            childPositions->insertBack(newPosition);
        }
    }

    ~GeneralPosition() { delete childPositions; };

    E operator*() const { return node->getElem(); };
    GeneralNode<E> *getNode() { return node; };
    GeneralPosition<E> *getParent() const { return new GeneralPosition<E>(node->getParent()); };
    NodeList<GeneralPosition<E>*> *getChildren() const { return childPositions; };

    bool isRoot() const { return node->getParent() == nullptr; };
    bool isExternal() const { return childPositions->size() <= 0; };

    GeneralPosition<E> *addNode(E elem) {
        GeneralNode<E> *newNode = node->addNode(elem);
        GeneralPosition<E> *newPosition = new GeneralPosition<E>(newNode);

        childPositions->insertBack(newPosition);

        return newPosition;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
