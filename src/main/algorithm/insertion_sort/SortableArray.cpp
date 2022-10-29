#include "SortableArray.h"

SortableArray::SortableArray(int size) {
    chars = new char[size];
    length = 0;
}

SortableArray::~SortableArray() {
    delete[] chars;
}

void SortableArray::insertionSort() {
    for (int pivotIdx = 1; pivotIdx < length; pivotIdx++) {
        char cur = chars[pivotIdx];

        int targetIdx = shiftElemsGreaterThan(pivotIdx, cur);

        chars[targetIdx] = cur;
    }
}

int SortableArray::shiftElemsGreaterThan(int pivotIdx, char cur) {
    int leftIdx = pivotIdx - 1;

    while ((leftIdx >= 0) && (chars[leftIdx] > cur)) {
        chars[leftIdx + 1] = chars[leftIdx];
        leftIdx--;
    }

    int targetIdx = leftIdx + 1;
    return targetIdx;
}

void SortableArray::add(char data) {
    chars[length] = data;
    length++;
}

string SortableArray::toString() {
    string result = "[ ";

    for(int i = 0; i < length; i++) {
        result += chars[i];
        if (i != length - 1) {
            result += ", ";
        } else {
            result += " ]";
        }
    }

    return result;
}
