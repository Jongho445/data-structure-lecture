#ifndef DATA_STRUCTURE_LECTURE_STRINGLINKEDLIST_H
#define DATA_STRUCTURE_LECTURE_STRINGLINKEDLIST_H

#include "string"
#include "StringNode.h"

using namespace std;

class StringLinkedList {
public:
    StringLinkedList();
    ~StringLinkedList();

    bool isEmpty() const;
    void addFront(const string& elem);
    void removeFront();

    string toString();
private:
    StringNode* head;
};


#endif //DATA_STRUCTURE_LECTURE_STRINGLINKEDLIST_H
