#ifndef DATA_STRUCTURE_LECTURE_BINARYTREETEST_H
#define DATA_STRUCTURE_LECTURE_BINARYTREETEST_H


#include "iostream"
#include "../../main/tree/binary/LinkedBinaryTree.h"
#include "../../main/tree/binary/BinaryNode.h"

using namespace std;

class BinaryTreeTest {
public:
    static void run() {
        LinkedBinaryTree<int> tree = createTree();

        cout << "length is ";
        cout << tree.getLength() << endl;

        tree.printTree(tree.getRoot());
        cout << endl;

        BinaryPosition<int> leaf = tree.getRoot().getLeft().getRight();
        tree.removeAboveExternal(leaf);

        tree.printTree(tree.getRoot());
        cout << endl;

        NodeList<BinaryPosition<int>> *positions = tree.getPositions();
        Iterator<BinaryPosition<int>> iter = positions->begin();
        while (iter != positions->end()) {
            cout << **iter;
            cout << " ";
            ++iter;
        }
        cout << endl;

        delete positions;
    }

    static LinkedBinaryTree<int> createTree() {
        LinkedBinaryTree<int> tree = LinkedBinaryTree<int>();

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

#endif //DATA_STRUCTURE_LECTURE_BINARYTREETEST_H
