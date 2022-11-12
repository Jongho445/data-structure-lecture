#ifndef DATA_STRUCTURE_LECTURE_TREE_H
#define DATA_STRUCTURE_LECTURE_TREE_H

#include "Position.h"
#include "TreeHelper.h"
#include "../../adt/node_list/NodeList.h"

using namespace std;

template <typename E>
class Tree {
private:
    Position<E> *root;
    NodeList<Position<E>*> *positions;
public:
    Tree(E elem) {
        root = new Position<E>(elem, nullptr);

        positions = new NodeList<Position<E>*>();
        positions->insertBack(root);
    }

    ~Tree() {
        delete positions;
    }

    int size() const { return positions->size(); };
    bool empty() const { root == nullptr; };

    Position<E> *getRoot() const { return root; };
    NodeList<Position<E>*> *getPositions() const { return positions; };

    int getHeight() {
        int height = 0;
        NodeList<Position<E>*> *nodes = this->getPositions();
        for (Iterator<Position<E>*> iter = nodes->begin(); iter != nodes->end(); ++iter) {
            if ((*iter)->isExternal()) {
                height = TreeHelper::max(height, TreeHelper::depth(*iter));
            }
        }
        return height;
    }

    void preorderPrint() {
        TreeHelper::preorderPrint(root);
        cout << endl;
    }

    void postorderPrint() {
        TreeHelper::postorderPrint(root);
        cout << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREE_H
