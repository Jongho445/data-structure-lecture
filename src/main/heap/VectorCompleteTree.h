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
    int getIdxOf(Position pos) { return pos - list.begin(); }
public:
    VectorCompleteTree(): list(vector<E>(1)) {}

    // vector complete tree는 맨 앞의 원소를 사용하지 않기에 lastIdx와 length가 같다
    // (lastIdx == length - 1이 아니라는 말이다)
    int getLastIdx() const {
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

    // vector complete tree는 맨 앞의 원소를 사용하지 않기에 rootIdx는 0이 아닌 1이다
    Position getRoot() {
        return getPosition(1);
    }

    Position getLast() {
        return getPosition(getLastIdx());
    }

    Position getParentOf(Position pos) {
        return getPosition(getIdxOf(pos) / 2);
    }

    Position getLeftOf(Position pos) {
        return getPosition(2 * getIdxOf(pos));
    }

    Position getRightOf(Position pos) {
        return getPosition(2 * getIdxOf(pos) + 1);
    }

    bool hasLeft(Position pos) {
        return (2 * getIdxOf(pos)) <= getLastIdx();
    }

    bool hasRight(Position pos) {
        return ((2 * getIdxOf(pos)) + 1) <= getLastIdx();
    }

    bool isRoot(Position pos) {
        return getIdxOf(pos) == 1;
    }
};

#endif //DATA_STRUCTURE_LECTURE_VECTORCOMPLETETREE_H
