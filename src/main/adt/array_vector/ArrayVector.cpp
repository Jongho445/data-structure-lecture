#include "ArrayVector.h"

ArrayVector::ArrayVector(): capacity(0), length(0), arr(nullptr) { }

int ArrayVector::size() const { return length; }
bool ArrayVector::empty() const { return size() == 0; }

Elem& ArrayVector::operator[](int i) { return arr[i]; }

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
    if (i < 0 || i >= length) {
        throw IndexOutOfBounds("illegal index in function at()");
    }

    return arr[i];
}

void ArrayVector::erase(int idx) {
    for (int j = idx + 1; j < length; j++) {
        arr[j - 1] = arr[j];
    }

    length--;
}

void ArrayVector::reserve(int newCapacity) {
    if (capacity >= newCapacity) {
        return;
    }

    Elem* newArr = new Elem[newCapacity];
    for (int j = 0; j < length; j++) {
        newArr[j] = arr[j];
    }

    if (arr != nullptr) {
        delete [] arr;
    }

    arr = newArr;
    capacity = newCapacity;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void ArrayVector::insert(int idx, const Elem& elem) {
    if (length >= capacity) {
        reserve(max(1, 2 * capacity));
    }

    for (int j = length - 1; j >= idx; j--) {
        arr[j + 1] = arr[j];
    }

    arr[idx] = elem; // put in empty slot
    length++; // one more element
}


