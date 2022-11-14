#ifndef DATA_STRUCTURE_LECTURE_GENERALTREE_H
#define DATA_STRUCTURE_LECTURE_GENERALTREE_H

#include "vector"
#include "GeneralNode.h"
#include "GeneralPosition.h"
#include "GeneralTreeHelper.h"
#include "../Traversal.h"

template <typename E>
class GeneralTree {
protected:
    typedef GeneralNode<E> Node;
    typedef GeneralPosition<E> Position;
    typedef typename vector<GeneralPosition<E>>::iterator Iterator;

    Node *root;
    int length;
public:
    GeneralTree(): root(nullptr), length(0) {}
    GeneralTree(E elem): root(new Node(elem, nullptr)), length(1) {}

    ~GeneralTree() {
        vector<Position> *positions = getPositions(Traversal::PREORDER);
        for (Iterator iter = positions->begin(); iter != positions->end(); ++iter) {
            Node *node = (*iter).getNode();
            delete node;
        }
        
        delete positions;
    }

    bool isEmpty() const { return length == 0; };

    void addRoot(E elem) {
        root = new Node(elem, nullptr);
        length++;
    }

    void addNode(E elem, Position position) {
        position.getNode()->addNode(elem);
        length++;
    }

    Position getRoot() const {
        return Position(root);
    };

    int getLength() const { return length; };

    int getHeight() {
        int height = 0;

        vector<Position> *positions = getPositions(Traversal::PREORDER);
        for (Iterator iter = positions->begin(); iter != positions->end(); ++iter) {
            if ((*iter).isExternal()) {
                height = GeneralTreeHelper::max(height, GeneralTreeHelper::depth(*iter));
            }
        }

        return height;
    }

    vector<Position> *getPositions(Traversal traversal) {
        vector<Position> *positions = new vector<Position>();
        switch (traversal) {
            case PREORDER: pushPreorder(getRoot(), positions); break;
            case POSTORDER: pushPostorder(getRoot(), positions); break;
            case INORDER: break;
        }

        return positions;
    };

    void printTree(Traversal traversal) {
        vector<Position> *positions = getPositions(traversal);

        for (Iterator iter = positions->begin(); iter != positions->end(); ++iter) {
            cout << **iter;
            cout << " ";
        }
        cout << endl;

        delete positions;
    }
private:
    void pushPreorder(Position target, vector<Position> *positions) {
        positions->push_back(target);

        vector<Position> *children = target.getChildren();
        for (Iterator iter = children->begin(); iter != children->end(); ++iter) {
            pushPreorder(*iter, positions);
        }
    }

    void pushPostorder(Position target, vector<Position> *positions) {
        vector<Position> *children = target.getChildren();
        for (Iterator iter = children->begin(); iter != children->end(); ++iter) {
            pushPostorder(*iter, positions);
        }

        positions->push_back(target);
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREE_H
