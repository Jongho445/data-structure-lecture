#ifndef DATA_STRUCTURE_LECTURE_TREETEST_H
#define DATA_STRUCTURE_LECTURE_TREETEST_H

#include "string"
#include "../../main/tree/Tree.h"

using namespace std;

class TreeTest {
public:
    static void run() {
        string str1 = "1st";
        Tree<string> tree = Tree<string>(&str1);

        string str2 = "2nd";
        const Position<string> &position1 = Position<string>(&str2, tree.getRoot());
        tree.getRoot()->getChildren()->insertBack(position1);

        string str3 = "3rd";
        const Position<string> &position2 = Position<string>(&str3, tree.getRoot());
        tree.getRoot()->getChildren()->insertBack(position2);
        
        string *f = tree.getRoot()->getChildren()->getFront().operator*();
        string *b = tree.getRoot()->getChildren()->getBack().operator*();
        cout << *f << endl;
        cout << *b << endl;

        cout << tree.depth(tree, position2) << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_TREETEST_H
