#ifndef DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
#define DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H

#include "string"

using namespace std;

class SortableArray {
public:
    SortableArray(int size);
    ~SortableArray();

    void insertionSort();

    void add(char data);
    string toString();
private:
    char *chars;
    int length;

    int shiftElemsGreaterThan(int pivotIdx, char cur);
};


#endif //DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
