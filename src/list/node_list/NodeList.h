#ifndef DATA_STRUCTURE_LECTURE_NODELIST_H
#define DATA_STRUCTURE_LECTURE_NODELIST_H


#include "string"
#include "Node.h"

using namespace std;

typedef string Elem;

class NodeList {
public:
    class Iterator {
    public:
        Elem& operator*();

        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;

        Iterator& operator++();
        Iterator& operator--();

        friend class NodeList;
    private:
        Iterator(Node* u);
        Node* v;
    };

    NodeList();

    int size() const;
    bool empty() const;

    Iterator begin() const;
    Iterator end() const;

    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void insert(const Iterator& p, const Elem& e);

    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);

private:
    int n;
    Node* header;
    Node* trailer;
};


#endif //DATA_STRUCTURE_LECTURE_NODELIST_H
