#ifndef DATA_STRUCTURE_LECTURE_CNODE_H
#define DATA_STRUCTURE_LECTURE_CNODE_H


#include "string"

using namespace std;

typedef string Elem;

class CNode {
public:
    CNode();

    string toString();
    string toString(CNode *node);
private:
    Elem elem;
    CNode* next;

    friend class CircleList;
};


#endif //DATA_STRUCTURE_LECTURE_CNODE_H
