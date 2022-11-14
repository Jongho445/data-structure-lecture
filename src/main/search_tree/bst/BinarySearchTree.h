#ifndef DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H


#include "BinarySearchTreeIterator.h"
#include "../../tree/binary/BinaryPosition.h"
#include "../../tree/binary/LinkedBinaryTree.h"

template <typename E, typename K, typename V>
class BinarySearchTree {
private:
    LinkedBinaryTree<E> tree;
    int length;

    typedef BinaryPosition<E> Position;
    typedef BinarySearchTreeIterator<E> Iterator;
public:
    BinarySearchTree() {}

    bool isEmpty() {}

    Iterator begin() {}
    Iterator end() {}

    Iterator find(K key, Position pos) {}

    Iterator insert(K key, V value) {}

    void erase(K key) {}

    void erase(Iterator iter) {}
protected:
    Position getRoot() {}

    Position finder(K key, Position pos) {}

    Position inserter(K key, V value) {}

    Position eraser(Position pos) {}

    Position restructure(Position pos) {}

};

#endif //DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H
