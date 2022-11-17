#ifndef DATA_STRUCTURE_LECTURE_INSERTIONSORTARRAY_H
#define DATA_STRUCTURE_LECTURE_INSERTIONSORTARRAY_H


#include "SortableArray.h"

template <typename E>
class InsertionSortArray : public SortableArray<E> {
public:
    InsertionSortArray(int capacity) : SortableArray<E>(capacity) {}

    virtual void sort() {
        for (int pivotIdx = 1; pivotIdx < this->size; pivotIdx++) {
            E cur = this->arr[pivotIdx];

            int targetIdx = shiftElemsGreaterThan(pivotIdx, cur);

            this->arr[targetIdx] = cur;
        }
    }

private:
    int shiftElemsGreaterThan(int pivotIdx, char cur) {
        int leftIdx = pivotIdx - 1;

        while ((leftIdx >= 0) && (this->arr[leftIdx] > cur)) {
            this->arr[leftIdx + 1] = this->arr[leftIdx];
            leftIdx--;
        }

        int targetIdx = leftIdx + 1;
        return targetIdx;
    }
};

#endif //DATA_STRUCTURE_LECTURE_INSERTIONSORTARRAY_H
