#ifndef DATA_STRUCTURE_LECTURE_GENERALTREE_H
#define DATA_STRUCTURE_LECTURE_GENERALTREE_H

#include "GeneralNode.h"
#include "GeneralPosition.h"
#include "GeneralTreeHelper.h"
#include "../Traversal.h"
#include "../../adt/node_list/NodeList.h"

template <typename E>
class GeneralTree {
private:
    GeneralNode<E> *root;
    int length;
public:
    GeneralTree(): root(nullptr), length(0) {}
    GeneralTree(E elem): root(new GeneralNode<E>(elem, nullptr)), length(1) {}

    ~GeneralTree() {
        NodeList<GeneralPosition<E>> *positions = getPositions();
        for (Iterator<GeneralPosition<E>> iter = positions->begin(); iter != positions->end(); ++iter) {
            GeneralNode<E> *node = (*iter).getNode();
            delete node;
        }
        
        delete positions;
    }

    bool isEmpty() const { return length == 0; };

    void addRoot(E elem) {
        root = new GeneralNode<E>(elem, nullptr);
        length++;
    }

    void addNode(E elem, GeneralPosition<E> position) {
        position.getNode()->addNode(elem);
        length++;
    }

    GeneralPosition<E> getRoot() const {
        return GeneralPosition<E>(root);
    };

    int getLength() const { return length; };

    int getHeight() {
        int height = 0;

        NodeList<GeneralPosition<E>> *positions = getPositions();
        for (Iterator<GeneralPosition<E>> iter = positions->begin(); iter != positions->end(); ++iter) {
            if ((*iter).isExternal()) {
                height = GeneralTreeHelper::max(height, GeneralTreeHelper::depth(*iter));
            }
        }

        return height;
    }

    NodeList<GeneralPosition<E>> *getPositions() {
        NodeList<GeneralPosition<E>> *positions = new NodeList<GeneralPosition<E>>();
        pushPreorder(getRoot(), positions);

        return positions;
    };

    NodeList<GeneralPosition<E>> *getPositions(Traversal traversal) {
        NodeList<GeneralPosition<E>> *positions = new NodeList<GeneralPosition<E>>();
        switch (traversal) {
            case PREORDER: pushPreorder(getRoot(), positions); break;
            case POSTORDER: pushPostorder(getRoot(), positions); break;
            case INORDER: break;
        }

        return positions;
    };

    void pushPreorder(GeneralPosition<E> target, NodeList<GeneralPosition<E>> *positions) {
        positions->insertBack(target);

        NodeList<GeneralPosition<E>> *children = target.getChildren();
        for (Iterator<GeneralPosition<E>> iter = children->begin(); iter != children->end(); ++iter) {
            pushPreorder(*iter, positions);
        }
    }

    void pushPostorder(GeneralPosition<E> target, NodeList<GeneralPosition<E>> *positions) {
        NodeList<GeneralPosition<E>> *children = target.getChildren();
        for (Iterator<GeneralPosition<E>> iter = children->begin(); iter != children->end(); ++iter) {
            pushPostorder(*iter, positions);
        }

        positions->insertBack(target);
    }

    void printTree(Traversal traversal) {
        NodeList<GeneralPosition<E>> *positions = getPositions(traversal);

        for (Iterator<GeneralPosition<E>> iter = positions->begin(); iter != positions->end(); ++iter) {
            cout << **iter;
            cout << " ";
        }
        cout << endl;

        delete positions;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREE_H
