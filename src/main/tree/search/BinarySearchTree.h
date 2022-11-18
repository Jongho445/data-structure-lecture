#ifndef DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H


#include "BinarySearchTreeIterator.h"
#include "../binary/BinaryPosition.h"
#include "../binary/FullBinaryTree.h"
#include "../../exception/NotExistElement.h"

template <typename K, typename V>
class BinarySearchTree {
private:
    typedef BinaryPosition<Entry<K, V>*> Position;
    typedef BinarySearchTreeIterator<K, V> Iterator;
    typedef FullBinaryTree<Entry<K, V>*> BinaryTree;

    BinaryTree tree;
    int length;
public:
    BinarySearchTree() : tree(BinaryTree()), length(0) {
        tree.addRoot();
        tree.expandExternal(tree.getRoot());
    }

    bool isEmpty() { return length == 0; }

    Iterator begin() {
        // pos == BstRoot
        Position pos = getBstRoot();

        // pos를 왼쪽 끝의 exteranalNode까지 이동시킴
        while (pos.isInternal()) {
            pos = pos.getLeft();
        }

        // 왼쪽 끝 externalNode의 부모(최초의 유효 노드)부터 시작
        return Iterator(pos.getParent());
    }

    Iterator end() {
        // root 노드가 곧 end 노드이다.
        // root 노드는 BstRoot와 다름을 주의하자. BstRoot는 root.left이다.
        return Iterator(tree.getRoot());
    }

    Iterator find(K key) {
        Position pos = finder(key, getBstRoot());

        if (pos.isExternal()) {
            throw NotExistElement("this key does Not Exist!");
        }

        return Iterator(pos);
    }

    Iterator insert(K key, V value) {
        Position pos = inserter(key, value);

        return Iterator(pos);
    }

    void erase(K key) throw(NotExistElement){
        Position pos = finder(key, getBstRoot());

        if (pos.isExternal()) {
            throw NotExistElement("this key does Not Exist!");
        }

        eraser(pos);
    }

    void erase(Iterator iter) {
        eraser(iter.getPosition());
    }

    void printTree() {
        for (Iterator iter = begin(); iter != end(); ++iter) {
            cout << **iter;
            cout << ", ";
        }
        cout << endl;
    }

protected:
    Position getBstRoot() {
        return tree.getRoot().getLeft();
    }

    Position finder(K key, Position pos) {
        if (pos.isExternal()) {
            return pos;
        }

        if (key < (*pos)->getKey()) {
            return finder(key, pos.getLeft());
        } else if ((*pos)->getKey() < key) {
            return finder(key, pos.getRight());
        }

        // (*pos)->getKey() == key
        return pos;
    }

    Position inserter(K key, V value) {
        Position pos = finder(key, getBstRoot());

        while (pos.isInternal()) {
            pos = finder(key, pos.getRight());
        }

        pos.getNode()->setElem(new Entry<K, V>(key, value));
        tree.expandExternal(pos);
        length++;

        return pos;
    }

    Position eraser(Position pos) {
        Position desc = getDescendant(pos);

        length--;
        return tree.removeAboveExternal(desc);
    }

    Position getDescendant(Position pos) {
        if (pos.getLeft().isExternal()) {
            return pos.getLeft();
        } else if (pos.getRight().isExternal()) {
            return pos.getRight();
        }

        // 자손 (descendant)
        Position desc = pos.getRight();

        do {
            desc = desc.getLeft();
        } while (desc.isInternal());

        Position parentDesc = desc.getParent();
        Entry<K, V> *parentEntry = *parentDesc;

        pos.getNode()->setElem(parentEntry);

        return desc;
    }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYSEARCHTREE_H
