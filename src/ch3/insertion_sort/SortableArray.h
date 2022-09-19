#ifndef DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
#define DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H

#include "string"

using namespace std;

class SortableArray {
public:
    SortableArray(char *arr, int size);

    void insertionSort();
    string toString();
private:
    char *chars;
    int length;
};


#endif //DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
