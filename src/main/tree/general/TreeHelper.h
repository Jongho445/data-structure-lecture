#ifndef DATA_STRUCTURE_LECTURE_TREEHELPER_H
#define DATA_STRUCTURE_LECTURE_TREEHELPER_H

#include "Position.h"

class TreeHelper {
public:
    template <typename E>
    static int depth(Position<E> *position) {
        if (position->isRoot())
            return 0;
        else
            return 1 + depth(position->getParent());
    }

    static int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    template <typename E>
    static int getHeightOfPosition(Position<E> *position) {
        if (position->isExternal()) {
            return 0;
        }

        int height = 0;
        NodeList<Position<E>*> *children = position->getChildren();
        for (Iterator<Position<E>*> iter = children->begin(); iter != children->end(); ++iter) {
            height = max(height, getHeightOfPosition(*iter));
        }

        return 1 + height;
    }
    
    template <typename E>
    static void preorderPrint(Position<E> *position) {
        cout << **position;
        
        NodeList<Position<E>*> *children = position->getChildren();
        for (Iterator<Position<E>*> iter = children->begin(); iter != children->end(); ++iter) {
            cout << " ";
            preorderPrint(*iter);
        }
    }
    
    template <typename E>
    static void postorderPrint(Position<E> *position) {
        NodeList<Position<E>*> *children = position->getChildren();
        for (Iterator<Position<E>*> iter = children->begin(); iter != children->end(); ++iter) {
            postorderPrint(*iter);
            cout << " ";
        }
        
        cout << **position;
    }

    template <typename E>
    static int diskSpace(Position<E> *position) {
        int size = getSize(position);

        if (!position->isExternal()) {
            NodeList<Position<E>*> *children = position->getChildren();
            for (Iterator<Position<E>*> iter = children->begin(); iter != children->end(); ++iter) {
                size += diskSpace(*iter);
            }
            cout << getName(position) << ": " << size << endl;
        }

        return size;
    }

    template <typename E>
    static int getSize(Position<E> *p) {
        return 10;
    }

    template <typename E>
    static E getName(Position<E> *p) {
        return **p;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREEHELPER_H
