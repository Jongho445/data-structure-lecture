#ifndef DATA_STRUCTURE_LECTURE_TREETEST_H
#define DATA_STRUCTURE_LECTURE_TREETEST_H

#include "string"
#include "../../main/tree/Tree.h"

using namespace std;

class TreeTest {
public:
    static void run() {
        Tree<string> tree = createTree();
        
        string f = tree.getRoot()->getChildren()->getFront().operator*();
        string b = tree.getRoot()->getChildren()->getBack().operator*();
        cout << f << endl;
        cout << b << endl;

        cout << tree.height1(tree) << endl;
        cout << tree.height2(tree, *tree.getRoot()) << endl;
    }

    static Tree<string> createTree() {
        Tree<string> tree = Tree<string>("1st");

        const Position<string> &position1 = Position<string>("2nd", tree.getRoot());
        tree.getRoot()->getChildren()->insertBack(position1);
        tree.getPositions()->insertBack(position1);

        const Position<string> &position2 = Position<string>("3rd", tree.getRoot());
        tree.getRoot()->getChildren()->insertBack(position2);
        tree.getPositions()->insertBack(position2);

        return tree;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREETEST_H
