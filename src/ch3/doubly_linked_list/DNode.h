#ifndef DATA_STRUCTURE_LECTURE_DNODE_H
#define DATA_STRUCTURE_LECTURE_DNODE_H


#include "string"

using namespace std;

typedef string Elem;

class DNode {
public:
    DNode();

    string toString();
    string toString(DNode *node);
private:
    Elem elem;
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};

#endif //DATA_STRUCTURE_LECTURE_DNODE_H
