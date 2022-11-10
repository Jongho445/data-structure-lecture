#ifndef DATA_STRUCTURE_LECTURE_TREE_H
#define DATA_STRUCTURE_LECTURE_TREE_H

#include "Position.h"
#include "../adt/node_list/NodeList.h"

using namespace std;

template <typename E>
class Tree {
private:
    Position<E> *root;
    NodeList<Position<E>> *positions;
public:
    Tree(E *elem) {
        this->root = new Position<E>(elem, nullptr);
        this->positions = new NodeList<Position<E>>();
    }

    ~Tree() {
        delete positions;
    }

    int size() const { return positions->size(); };
    bool empty() const { root == nullptr; };
    Position<E> *getRoot() const { return root; };
    NodeList<Position<E>> *getPositions() const { return positions; };

    int depth(const Tree &T, const Position<E> &p) {
        if (p.isRoot())
            return 0;
        else
            return 1 + depth(T, *p.getParent());
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREE_H
