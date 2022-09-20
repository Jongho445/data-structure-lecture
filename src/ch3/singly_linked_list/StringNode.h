#ifndef DATA_STRUCTURE_LECTURE_STRINGNODE_H
#define DATA_STRUCTURE_LECTURE_STRINGNODE_H


#include "string"

using namespace std;

class StringNode {
private:
    string elem;
    StringNode* next;

    friend class StringLinkedList;
};


#endif //DATA_STRUCTURE_LECTURE_STRINGNODE_H
