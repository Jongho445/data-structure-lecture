#ifndef DATA_STRUCTURE_LECTURE_BINARYSEARCHTREETEST_H
#define DATA_STRUCTURE_LECTURE_BINARYSEARCHTREETEST_H


#include "../../main/search_tree/bst/BinarySearchTree.h"

using namespace std;

class BinarySearchTreeTest {
public:
    static void run() {
        BinarySearchTree<int, string> tree = createTree();

        tree.erase(5);
        tree.printTree();
    }

    static BinarySearchTree<int, string> createTree() {
        BinarySearchTree<int, string> tree = BinarySearchTree<int, string>();
        tree.insert(5, "a");
        tree.insert(3, "b");
        tree.insert(2, "c");
        tree.insert(7, "d");
        tree.insert(12, "e");
        tree.insert(4, "f");
        tree.insert(10, "g");

        return tree;
    }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYSEARCHTREETEST_H
