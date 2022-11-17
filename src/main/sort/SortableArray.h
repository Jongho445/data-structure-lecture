#ifndef DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
#define DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H

template <typename E>
class SortableArray {
protected:
    E *arr;
    int size;
public:
    SortableArray(int capacity) {
        arr = new E[capacity];
        size = 0;
    }

    ~SortableArray() {
        delete[] arr;
    }

    virtual void sort() = 0;

    void add(E data) {
        arr[size] = data;
        size++;
    }

    void print() {
        cout << "[ ";
        for(int i = 0; i < size; i++) {
            cout << arr[i];
            if (i != size - 1) {
                cout << ", ";
            } else {
                cout << " ]" << endl;
            }
        }
    }
};


#endif //DATA_STRUCTURE_LECTURE_SORTABLEARRAY_H
