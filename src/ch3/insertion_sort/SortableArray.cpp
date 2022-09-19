#include "SortableArray.h"

SortableArray::SortableArray(char *arr, int size): chars(arr), length(size) {}

void SortableArray::insertionSort() {
    for (int i = 1; i < length; i++) {
        char cur = chars[i];
        int j = i - 1;
        while ((j >= 0) && (chars[j] > cur)) {
            chars[j + 1] = chars[j];
            j--;
        }
        chars[j + 1] = cur;
    }
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
