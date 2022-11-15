#ifndef DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H
#define DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H


#include "../../hash/Entry.h"
#include "../binary/BinaryPosition.h"

template <typename K, typename V>
class BinarySearchTreeIterator {
private:
    typedef BinaryPosition<Entry<K, V>> Position;
    typedef BinarySearchTreeIterator<K, V> Iterator;

    Position pos;
public:
    BinarySearchTreeIterator(Position pos): pos(pos) {}

    Position getPosition() { return pos; }

    Entry<K, V> operator*() { return *pos; }

    bool operator==(Iterator iter) { return pos == iter.pos; }
    bool operator!=(Iterator iter) { return pos != iter.pos; }

    Iterator operator++() {
        Position desc = pos.getRight();

        if (desc.isInternal()) {
            do {
                pos = desc;
                desc = desc.getLeft();
            } while (desc.isInternal());
        } else {
            Position ancestor = pos.getParent();

            while (pos == ancestor.getRight()) {
                pos = ancestor;
                ancestor = ancestor.getParent();
            }

            pos = ancestor;
        }

        return *this;
    }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H
