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

    int getLength() const { return tree.getLength(); }
    bool isEmpty() const { return getLength() == 0; }

    E min() { return *(tree.getRoot()); }

    void insert(E elem) {
        tree.addLast(elem);
        Position target = tree.getLast();
        while (!tree.isRoot(target)) {
            Position parent = tree.getParent(target);

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
        
        while (tree.hasLeft(target)) {
            // 자식 노드가 왼쪽 노드인지 오른쪽 노드인지 선택
            Position child = tree.getLeft(target);
            if (tree.hasRight(target) && !isGraterThen(*(tree.getRight(target)), *child)) {
                child = tree.getRight(target);
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
