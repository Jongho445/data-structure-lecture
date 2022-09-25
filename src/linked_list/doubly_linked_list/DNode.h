#ifndef DATA_STRUCTURE_LECTURE_DNODE_H
#define DATA_STRUCTURE_LECTURE_DNODE_H


#include "string"

using namespace std;

typedef string Elem;

class DNode {
public:
    DNode();
    DNode(Elem elem, DNode *prev, DNode *next);

    string toString();
    string toString(DNode *node);
private:
    Elem elem;
    DNode* prev;
    DNode* next;

    bool isHeader();
    bool isTrailer();

    friend class DLinkedList;
    friend class DoublyLinkedListTest;
};

#endif //DATA_STRUCTURE_LECTURE_DNODE_H
