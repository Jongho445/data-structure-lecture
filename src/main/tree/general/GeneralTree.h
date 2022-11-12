#ifndef DATA_STRUCTURE_LECTURE_GENERALTREE_H
#define DATA_STRUCTURE_LECTURE_GENERALTREE_H

#include "GeneralNode.h"
#include "GeneralPosition.h"
#include "GeneralTreeHelper.h"
#include "../../adt/node_list/NodeList.h"

template <typename E>
class GeneralTree {
private:
    GeneralNode<E> *root;
    NodeList<GeneralPosition<E>*> *positions;
public:
    GeneralTree(E elem) {
        root = new GeneralNode<E>(elem, nullptr);

        positions = new NodeList<GeneralPosition<E>*>();
        positions->insertBack(new GeneralPosition<E>(root));
    }

    ~GeneralTree() {
        delete positions;
    }

    int size() const { return positions->size(); };
    bool empty() const { root == nullptr; };

    GeneralPosition<E> *getRoot() const {
        return new GeneralPosition<E>(root);
    };

    NodeList<GeneralPosition<E>*> *getPositions() const { return positions; };
    
    void addNode(E elem, GeneralPosition<E> *position) {
        GeneralPosition<E> *newPosition = position->addNode(elem);
        positions->insertBack(newPosition);
    }

    int getHeight() {
        int height = 0;
        NodeList<GeneralPosition<E>*> *nodes = this->getPositions();
        for (Iterator<GeneralPosition<E>*> iter = nodes->begin(); iter != nodes->end(); ++iter) {
            if ((*iter)->isExternal()) {
                height = GeneralTreeHelper::max(height, GeneralTreeHelper::depth(*iter));
            }
        }
        return height;
    }

    void preorderPrint() {
        GeneralTreeHelper::preorderPrint(new GeneralPosition<E>(root));
        cout << endl;
    }

    void postorderPrint() {
        GeneralTreeHelper::postorderPrint(new GeneralPosition<E>(root));
        cout << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREE_H
