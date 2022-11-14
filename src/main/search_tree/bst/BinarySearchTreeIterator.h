#ifndef DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H
#define DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H


template <typename E>
class BinarySearchTreeIterator {
private:
    typedef BinaryPosition<E> Position;
    typedef BinarySearchTreeIterator<E> Iterator;

    Position pos;
public:
    BinarySearchTreeIterator(Position pos): pos(pos) {}

    E operator*() { return *pos; }

    bool operator==(Iterator iter) { return pos == iter.pos; }

    Iterator  operator++() {}
};

#endif //DATA_STRUCTURE_LECTURE_BINARYSEARCHTREEITERATOR_H
