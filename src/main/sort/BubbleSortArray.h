#ifndef DATA_STRUCTURE_LECTURE_BUBBLESORTARRAY_H
#define DATA_STRUCTURE_LECTURE_BUBBLESORTARRAY_H


#include "SortableArray.h"

template <typename E>
class BubbleSortArray : public SortableArray<E> {
public:
    BubbleSortArray(int capacity) : SortableArray<E>(capacity) {}

    virtual void sort() {
        for (int i = 0; i < this->size - 1; i++) {

            for (int j = 1; j < this->size - i; j++) {

                if (this->arr[j - 1] > this->arr[j]) {
                    swap(&(this->arr[j - 1]), &(this->arr[j]));
                }
            }
        }
    }

private:
    void swap(E* a, E* b) {
        E temp = *a;
        *a = *b;
        *b = temp;
    }
};

#endif //DATA_STRUCTURE_LECTURE_BUBBLESORTARRAY_H
