#ifndef DATA_STRUCTURE_LECTURE_GENERALTREE_H
#define DATA_STRUCTURE_LECTURE_GENERALTREE_H

#include "vector"
#include "GeneralNode.h"
#include "GeneralPosition.h"
#include "GeneralTreeHelper.h"
#include "../Traversal.h"

template <typename E>
class GeneralTree {
private:
    GeneralNode<E> *root;
    int length;
public:
    GeneralTree(): root(nullptr), length(0) {}
    GeneralTree(E elem): root(new GeneralNode<E>(elem, nullptr)), length(1) {}

    ~GeneralTree() {
        vector<GeneralPosition<E>> *positions = getPositions();
        typename vector<GeneralPosition<E>>::iterator iter;
        for (iter = positions->begin(); iter != positions->end(); ++iter) {
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

        vector<GeneralPosition<E>> *positions = getPositions();
        typename vector<GeneralPosition<E>>::iterator iter;
        for (iter = positions->begin(); iter != positions->end(); ++iter) {
            if ((*iter).isExternal()) {
                height = GeneralTreeHelper::max(height, GeneralTreeHelper::depth(*iter));
            }
        }

        return height;
    }

    vector<GeneralPosition<E>> *getPositions() {
        vector<GeneralPosition<E>> *positions = new vector<GeneralPosition<E>>();
        pushPreorder(getRoot(), positions);

        return positions;
    };

    vector<GeneralPosition<E>> *getPositions(Traversal traversal) {
        vector<GeneralPosition<E>> *positions = new vector<GeneralPosition<E>>();
        switch (traversal) {
            case PREORDER: pushPreorder(getRoot(), positions); break;
            case POSTORDER: pushPostorder(getRoot(), positions); break;
            case INORDER: break;
        }

        return positions;
    };

    void pushPreorder(GeneralPosition<E> target, vector<GeneralPosition<E>> *positions) {
        positions->push_back(target);

        vector<GeneralPosition<E>> *children = target.getChildren();
        typename vector<GeneralPosition<E>>::iterator iter;
        for (iter = children->begin(); iter != children->end(); ++iter) {
            pushPreorder(*iter, positions);
        }
    }

    void pushPostorder(GeneralPosition<E> target, vector<GeneralPosition<E>> *positions) {
        vector<GeneralPosition<E>> *children = target.getChildren();
        typename vector<GeneralPosition<E>>::iterator iter;
        for (iter = children->begin(); iter != children->end(); ++iter) {
            pushPostorder(*iter, positions);
        }

        positions->push_back(target);
    }

    void printTree(Traversal traversal) {
        vector<GeneralPosition<E>> *positions = getPositions(traversal);

        typename vector<GeneralPosition<E>>::iterator iter;
        for (iter = positions->begin(); iter != positions->end(); ++iter) {
            cout << **iter;
            cout << " ";
        }
        cout << endl;

        delete positions;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREE_H
