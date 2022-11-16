#ifndef DATA_STRUCTURE_LECTURE_HASHMAP_H
#define DATA_STRUCTURE_LECTURE_HASHMAP_H


#include "list"
#include "vector"
#include "functional"
#include "HashMapIterator.h"

template <typename K, typename V>
class HashMap {
private:
    typedef HashMapIterator<K, V> Iterator;
    typedef Entry<K, V> Entry;
    typedef list<Entry> Bucket;

    typedef typename Bucket::iterator BucketIterator;
    typedef typename vector<Bucket>::iterator BucketsIterator;

    int size;
    hash<K> h;
    vector<Bucket> buckets;
public:
    HashMap(int capacity = 100) : size(0), h(hash<K>()), buckets(vector<Bucket>()) {}

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    Iterator begin() {
        if (isEmpty()) {
            return end();
        }

        BucketsIterator bucketsIter = buckets.begin();
        while ((*bucketsIter).empty()) {
            ++bucketsIter;
        }

        return Iterator(&buckets, bucketsIter, (*bucketsIter).begin());
    }
    
    Iterator end() {
        return Iterator(&buckets, buckets.end());
    }

    Iterator find(K key) {}

    Iterator put(K key, V value) {}

    void erase(K key) {}

    void erase(Iterator iter) {}

private:
    Iterator finder(K key) {}

    Iterator inserter(Iterator iter, Entry entry) {}

    void eraser(Iterator iter) {}

    static void nextEntry(Iterator iter) {}

    static bool endOfBucket(Iterator iter) {}
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAP_H
