#ifndef DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H
#define DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H

#include "string"
#include "../../exception/IndexOutOfBounds.h"

typedef string Elem;

class ArrayVector {
public:
    ArrayVector();

    int size() const;
    bool empty() const;

    Elem& operator[](int i);
    Elem& at(int i) throw(IndexOutOfBounds);

    void erase(int i);
    void insert(int i, const Elem& e);

    void reserve(int N);
private:
    int capacity;
    int n;
    Elem* A;
};


#endif //DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H
