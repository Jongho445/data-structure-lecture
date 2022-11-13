#ifndef DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
#define DATA_STRUCTURE_LECTURE_GENERALPOSITION_H

#include "GeneralNode.h"
#include "../../adt/node_list/NodeList.h"

template <typename E>
class GeneralPosition {
private:
    GeneralNode<E> *node;
public:
    GeneralPosition(): node(nullptr) {}
    GeneralPosition(GeneralNode<E> *node): node(node) {}

    E operator*() const { return node->getElem(); };
    GeneralNode<E> *getNode() { return node; };
    GeneralPosition<E> getParent() const { return GeneralPosition<E>(node->getParent()); };

    NodeList<GeneralPosition<E>> *getChildren() const {
        NodeList<GeneralPosition<E>> *positions = new NodeList<GeneralPosition<E>>();
        
        NodeList<GeneralNode<E>*> *children = node->getChildren();
        for (Iterator<GeneralNode<E>*> iter = children->begin(); iter != children->end(); ++iter) {
            positions->insertBack(GeneralPosition<E>(*iter));
        }

        return positions;
    };

    bool isRoot() const { return node->getParent() == nullptr; };
    bool isExternal() const { return node->getChildren()->size() <= 0; };
};

#endif //DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
