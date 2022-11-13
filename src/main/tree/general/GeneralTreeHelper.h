#ifndef DATA_STRUCTURE_LECTURE_GENERALTREEHELPER_H
#define DATA_STRUCTURE_LECTURE_GENERALTREEHELPER_H

#include "GeneralPosition.h"

class GeneralTreeHelper {
public:
    template <typename E>
    static int depth(GeneralPosition<E> position) {
        if (position.isRoot()) {
            return 0;
        } else {
            return 1 + depth(position.getParent());
        }
    }

    static int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    template <typename E>
    static int getHeightOfPosition(GeneralPosition<E> position) {
        if (position.isExternal()) {
            return 0;
        }

        int height = 0;
        NodeList<GeneralPosition<E>> *children = position.getChildren();
        for (Iterator<GeneralPosition<E>> iter = children->begin(); iter != children->end(); ++iter) {
            height = max(height, getHeightOfPosition(*iter));
        }

        return 1 + height;
    }

    template <typename E>
    static int diskSpace(GeneralPosition<E> position) {
        int size = getSize(position);

        if (!position.isExternal()) {
            NodeList<GeneralPosition<E>> *children = position.getChildren();
            for (Iterator<GeneralPosition<E>> iter = children->begin(); iter != children->end(); ++iter) {
                size += diskSpace(*iter);
            }
            cout << getName(position) << " folder: " << size << endl;
        }

        return size;
    }

    template <typename E>
    static int getSize(GeneralPosition<E> p) {
        if (p.isExternal()) {
            return 10;
        } else {
            return 0;
        }
    }

    template <typename E>
    static E getName(GeneralPosition<E> p) {
        return *p;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREEHELPER_H
