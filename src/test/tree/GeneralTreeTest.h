#ifndef DATA_STRUCTURE_LECTURE_GENERALTREETEST_H
#define DATA_STRUCTURE_LECTURE_GENERALTREETEST_H

#include "string"
#include "../../main/tree/general/GeneralTree.h"
#include "../../main/tree/general/GeneralTreeHelper.h"
#include "../../main/tree/general/GeneralPosition.h"

using namespace std;

class GeneralTreeTest {
public:
    static void run() {
        GeneralTree<string> *tree = createTree();

        cout << tree->getHeight() << endl;
        cout << GeneralTreeHelper::getHeightOfPosition(tree->getRoot()) << endl;

        tree->preorderPrint();
        tree->postorderPrint();

        GeneralTreeHelper::diskSpace(tree->getRoot());
    }

    static GeneralTree<string> *createTree() {
        GeneralTree<string> *tree = new GeneralTree<string>("1st");

        GeneralPosition<string> *root = tree->getRoot();
        tree->addNode("2nd", root);
        tree->addNode("3rd", root);

        Iterator<GeneralPosition<string> *> iter = root->getChildren()->begin();
        GeneralPosition<string> *secondPosition = *iter;
        tree->addNode("4th", secondPosition);
        tree->addNode("5th", secondPosition);


        GeneralPosition<string> *&thirdPosition = *(++iter);
        tree->addNode("6th", thirdPosition);
        tree->addNode("7th", thirdPosition);

        return tree;
    }
};

#endif //DATA_STRUCTURE_LECTURE_GENERALTREETEST_H
