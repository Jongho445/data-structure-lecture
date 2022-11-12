#ifndef DATA_STRUCTURE_LECTURE_TREETEST_H
#define DATA_STRUCTURE_LECTURE_TREETEST_H

#include "string"
#include "../../main/tree/Tree.h"
#include "../../main/tree/TreeHelper.h"

using namespace std;

class TreeTest {
public:
    static void run() {
        Tree<string> *tree = createTree();

        Position<string> *frontPosition = tree->getRoot()->getChildren()->getFront();
        Position<string> *backPosition = tree->getRoot()->getChildren()->getBack();
        cout << **frontPosition << endl;
        cout << **backPosition << endl;

        cout << tree->getHeight() << endl;
        cout << TreeHelper::getHeightOfPosition(tree->getRoot()) << endl;

        tree->preorderPrint();
        tree->postorderPrint();

        TreeHelper::diskSpace(tree->getRoot());
    }

    static Tree<string> *createTree() {
        Tree<string> *tree = new Tree<string>("1st");

        Position<string> *position1 = new Position<string>("2nd", tree->getRoot());
        tree->getRoot()->getChildren()->insertBack(position1);
        tree->getPositions()->insertBack(position1);

        Position<string> *position2 = new Position<string>("3rd", tree->getRoot());
        tree->getRoot()->getChildren()->insertBack(position2);
        tree->getPositions()->insertBack(position2);

        return tree;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREETEST_H
