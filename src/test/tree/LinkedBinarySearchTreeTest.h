#ifndef DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREETEST_H
#define DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREETEST_H


#include "iostream"
#include "vector"
#include "../../main/tree/Traversal.h"
#include "../../main/tree/binary/LinkedBinaryTree.h"
#include "../../main/tree/binary/LinkedBinarySearchTree.h"
#include "../../main/tree/binary/BinaryNode.h"

using namespace std;

class LinkedBinarySearchTreeTest {
public:
    static void run() {
        LinkedBinarySearchTree<int> tree = createTree();

        cout << "length is ";
        cout << tree.getLength() << endl;

        tree.printTree(Traversal::INORDER);

        BinaryPosition<int> leaf = tree.getRoot().getLeft().getRight();
        tree.removeAboveExternal(leaf);

        tree.printTree(Traversal::INORDER);
    }

    static LinkedBinarySearchTree<int> createTree() {
        LinkedBinarySearchTree<int> tree = LinkedBinarySearchTree<int>();

        tree.addNode(5);
        tree.addNode(3);
        tree.addNode(2);
        tree.addNode(7);
        tree.addNode(12);
        tree.addNode(4);
        tree.addNode(10);

        return tree;
    }
};

#endif //DATA_STRUCTURE_LECTURE_LINKEDBINARYSEARCHTREETEST_H
