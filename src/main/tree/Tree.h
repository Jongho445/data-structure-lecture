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
    Tree(E elem) {
        Position<E> *rootPosition = new Position<E>(elem, nullptr);
        root = rootPosition;
        positions = new NodeList<Position<E>>();
        positions->insertBack(*rootPosition);
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

    int height1(const Tree<E>& T) {
        int h = 0;
        NodeList<Position<E>> nodes = *T.getPositions();
        for (Iterator<Position<E>> q = nodes.begin(); q != nodes.end(); ++q) {
            if ((q.operator*()).isExternal()) {
                h = max(h, depth(T, *q));
            }
        }
        return h;
    }

    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    int height2(const Tree<E>& T, const Position<E>& p) {
        if (p.isExternal()) {
            return 0;
        }

        int h = 0;
        NodeList<Position<E>> ch = *p.getChildren();
        for (Iterator<Position<E>> q = ch.begin(); q != ch.end(); ++q) {
            h = max(h, height2(T, *q));
        }

        return 1 + h;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREE_H
