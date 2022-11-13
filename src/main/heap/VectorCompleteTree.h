#ifndef DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H
#define DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H


#include "vector"

using namespace std;

template <typename E>
class VectorCompleteTree {
private:
    vector<E> list;
protected:
    typename vector<E>::iterator pos(int i) { return list.begin() + i; }
    int idx(typename vector<E>::iterator position) { return position - list.begin(); }
public:
    VectorCompleteTree(): list(vector<E>(1)) {}
    
    int getLength() const { return list.size() - 1; }
    vector<E> getList() { return list; }
    
    void addLast(E elem) { list.push_back(elem); }
    
    void removeLast() { list.pop_back(); }
    
    void swap(typename vector<E>::iterator p, typename vector<E>::iterator q) {
        E temp = *q;
        *q = *p;
        *p = temp;
    }

    typename vector<E>::iterator getRoot() { return pos(1); }
    typename vector<E>::iterator getLast() { return pos(getLength()); }

    typename vector<E>::iterator getParent(typename vector<E>::iterator position) {
        return pos(idx(position) / 2);
    }

    typename vector<E>::iterator getLeft(typename vector<E>::iterator position) {
        return pos(2 * idx(position));
    }

    typename vector<E>::iterator getRight(typename vector<E>::iterator position) {
        return pos(2 * idx(position) + 1);
    }

    bool hasLeft(typename vector<E>::iterator position) {
        return (2 * idx(position)) <= getLength();
    }

    bool hasRight(typename vector<E>::iterator position) {
        return ((2 * idx(position)) + 1) <= getLength();
    }

    bool isRoot(typename vector<E>::iterator position) {
        return idx(position) == 1;
    }
};

#endif //DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H
