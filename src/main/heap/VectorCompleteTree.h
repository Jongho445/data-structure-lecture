#ifndef DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H
#define DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H


#include "vector"

using namespace std;

template <typename E>
class VectorCompleteTree {
private:
    typedef typename vector<E>::iterator Position;

    vector<E> list;
protected:
    Position getPosition(int i) { return list.begin() + i; }
    int getIdx(Position pos) { return pos - list.begin(); }
public:
    VectorCompleteTree(): list(vector<E>(1)) {}
    
    int getLength() const {
        return list.size() - 1;
    }

    vector<E> getList() { return list; }
    
    void addLast(E elem) { list.push_back(elem); }
    void removeLast() { list.pop_back(); }
    
    void swap(Position p, Position q) {
        E temp = *q;
        *q = *p;
        *p = temp;
    }

    Position getRoot() { return getPosition(1); }
    Position getLast() { return getPosition(getLength()); }

    Position getParent(Position pos) {
        return getPosition(getIdx(pos) / 2);
    }

    Position getLeft(Position pos) {
        return getPosition(2 * getIdx(pos));
    }

    Position getRight(Position pos) {
        return getPosition(2 * getIdx(pos) + 1);
    }

    bool hasLeft(Position pos) {
        return (2 * getIdx(pos)) <= getLength();
    }

    bool hasRight(Position pos) {
        return ((2 * getIdx(pos)) + 1) <= getLength();
    }

    bool isRoot(Position pos) {
        return getIdx(pos) == 1;
    }
};

#endif //DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H
