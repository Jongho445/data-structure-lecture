#ifndef DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUE_H
#define DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUE_H


#include "vector"
#include "VectorCompleteTree.h"

template <typename E>
class HeapPriorityQueue {
private:
    typedef typename vector<E>::iterator Position;

    VectorCompleteTree<E> tree;
public:
    HeapPriorityQueue(): tree(VectorCompleteTree<E>()) {}

    int getLength() const { return tree.getLastIdx(); }
    bool isEmpty() const { return getLength() == 0; }

    E min() { return *(tree.getRoot()); }

    void insert(E elem) {
        tree.addLast(elem);
        Position target = tree.getLast();
        while (!tree.isRoot(target)) {
            Position parent = tree.getParentOf(target);

            // 기준 노드가 부모 노드보다 크면 heapify 종료, 작으면 swap
            if (isGraterThen(*target, *parent)) {
                break;
            }

            tree.swap(target, parent);
            target = parent;
        }
    }
    
    bool isGraterThen(E newElem, E parentElem) {
        if (newElem > parentElem) {
            return true;
        } else {
            return false;
        }
    }

    void removeMin() {
        if (getLength() == 1) {
            tree.removeLast();
            return;
        }

        Position target = tree.getRoot();
        tree.swap(target, tree.getLast());
        tree.removeLast();

        // 기준 노드(target)이 external 노드가 될 때까지 반복
        // (complete tree이므로 left 노드만 존재해도 internal 노드이다)
        while (tree.hasLeft(target)) {
            // 자식 노드가 왼쪽 노드인지 오른쪽 노드인지 선택
            Position child = tree.getLeftOf(target);
            if (tree.hasRight(target) && !isGraterThen(*(tree.getRightOf(target)), *child)) {
                child = tree.getRightOf(target);
            }

            // 자식 노드가 부모 노드보다 크면 종료, 작으면 swap
            if (isGraterThen(*child, *target)) {
                break;
            }

            tree.swap(target, child);
            target = child;
        }
    }

    void printQueue() {
        vector<E> list = tree.getList();
        Position iter = list.begin();
        ++iter;

        for (iter; iter != list.end(); ++iter) {
            cout << *iter;
            cout << " ";
        }
        cout << endl;
    }
};

#endif //DATA_STRUCTURE_LECTURE_HEAPPRIORITYQUEUE_H
