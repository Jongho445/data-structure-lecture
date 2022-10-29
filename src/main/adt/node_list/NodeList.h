#ifndef DATA_STRUCTURE_LECTURE_NODELIST_H
#define DATA_STRUCTURE_LECTURE_NODELIST_H


#include "string"
#include "../../linked_list/node/DNode.h"

using namespace std;

typedef string Elem;

class NodeList {
public:
    class Iterator {
    public:
        Elem &operator*();

        bool operator==(const Iterator& targetIter) const;
        bool operator!=(const Iterator& targetIter) const;

        Iterator &operator++();
        Iterator &operator--();

        friend class NodeList;
    private:
        Iterator(DNode *initNode);

        DNode *curNode;
    };

    NodeList();

    int size() const;
    bool empty() const;

    Iterator begin() const;
    Iterator end() const;

    void insertFront(const Elem& elem);
    void insertBack(const Elem& elem);
    void insert(const Iterator& targetIter, const Elem& elem);

    void eraseFront();
    void eraseBack();
    void erase(const Iterator& targetIter);

private:
    int length;

    DNode *header;
    DNode *trailer;
};


#endif //DATA_STRUCTURE_LECTURE_NODELIST_H
