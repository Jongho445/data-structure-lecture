#ifndef DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H
#define DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H

#include "string"
#include "../../exception/IndexOutOfBounds.h"

//typedef string Elem;
template <typename E>
class ArrayVector {
public:
    ArrayVector(): capacity(0), length(0), arr(nullptr) {}

    int size() const { return length; }
    bool empty() const { return size() == 0; }

    E& operator[](int i) { return arr[i]; }
    E& at(int i) throw(IndexOutOfBounds) {
        if (i < 0 || i >= length) {
            throw IndexOutOfBounds("illegal index in function at()");
        }

        return arr[i];
    }

    void reserve(int newCapacity) {
        if (capacity >= newCapacity) {
            return;
        }

        E* newArr = new E[newCapacity];
        for (int j = 0; j < length; j++) {
            newArr[j] = arr[j];
        }

        if (arr != nullptr) {
            delete [] arr;
        }

        arr = newArr;
        capacity = newCapacity;
    }

    void erase(int idx) {
        for (int j = idx + 1; j < length; j++) {
            arr[j - 1] = arr[j];
        }

        length--;
    }
    void insert(int idx, const E& elem) {
        if (length >= capacity) {
            reserve(max(1, 2 * capacity));
        }

        for (int j = length - 1; j >= idx; j--) {
            arr[j + 1] = arr[j];
        }

        arr[idx] = elem; // put in isEmpty slot
        length++; // one more element
    }
private:
    int capacity;
    int length;
    E* arr;

    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
};


#endif //DATA_STRUCTURE_LECTURE_ARRAYVECTOR_H
