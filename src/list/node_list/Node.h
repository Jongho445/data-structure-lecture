#ifndef DATA_STRUCTURE_LECTURE_NODE_H
#define DATA_STRUCTURE_LECTURE_NODE_H


#include "string"

using namespace std;

typedef string Elem;

class Node {
public:
    Node();
    Node(Elem elem, Node *prev, Node *next);
    string toString();
private:
    Elem elem;
    Node *prev;
    Node *next;

    friend class NodeList;
};


#endif //DATA_STRUCTURE_LECTURE_NODE_H
