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

    void erase(int idx);
    void insert(int idx, const Elem& elem);

    void reserve(int newCapacity);
private:
    int capacity;
    int length;
    Elem* arr;
};


#endif //DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H
