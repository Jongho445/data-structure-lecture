#ifndef DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
#define DATA_STRUCTURE_LECTURE_GENERALPOSITION_H

#include "vector"
#include "GeneralNode.h"

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

    vector<GeneralPosition<E>> *getChildren() const {
        vector<GeneralPosition<E>> *positions = new vector<GeneralPosition<E>>();

        vector<GeneralNode<E>*> *children = node->getChildren();
        typename vector<GeneralNode<E>*>::iterator iter;
        for (iter = children->begin(); iter != children->end(); ++iter) {
            positions->push_back(GeneralPosition<E>(*iter));
        }

        return positions;
    };

    bool isRoot() const { return node->getParent() == nullptr; };
    bool isExternal() const { return node->getChildren()->size() <= 0; };
};

#endif //DATA_STRUCTURE_LECTURE_GENERALPOSITION_H
