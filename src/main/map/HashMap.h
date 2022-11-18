#ifndef DATA_STRUCTURE_LECTURE_HASHMAP_H
#define DATA_STRUCTURE_LECTURE_HASHMAP_H


#include "list"
#include "vector"
#include "functional"
#include "HashMapIterator.h"

template <typename K, typename V>
class HashMap {
private:
    typedef HashMapIterator<K, V> MapIterator;
    typedef Entry<K, V> Entry;
    typedef list<Entry*> Bucket;
    typedef vector<Bucket*> BucketList;
    typedef typename Bucket::iterator BucketIterator;
    typedef typename BucketList::iterator BucketListIterator;

    BucketList *bl;

    int size;
    hash<K> h;
public:
    HashMap(int capacity = 100) : bl(new BucketList()), size(0), h(hash<K>()) {
        for (int i = 0; i < capacity; i++) {
            bl->push_back(new Bucket());
        }
    }

    ~HashMap() {
        for (BucketListIterator blIter = bl->begin(); blIter != bl->end(); ++blIter) {
            Bucket *bucket = *blIter;

            for (BucketIterator bIter = bucket->begin(); bIter != bucket->end(); ++bIter) {
                delete *bIter;
            }

            delete bucket;
        }

        delete bl;
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    MapIterator begin() {
        if (isEmpty()) {
            return end();
        }

        BucketListIterator blIter = bl->begin();
        while ((*blIter)->empty()) {
            ++blIter;
        }

        return MapIterator(bl, blIter, (*blIter)->begin());
    }
    
    MapIterator end() {
        return MapIterator(bl, bl->end());
    }

    MapIterator find(K key) {
        MapIterator mIter = finder(key);

        if (mIter.isLastEntityInBucket()) {
            return end();
        } else {
            return mIter;
        }
    }

    MapIterator put(K key, V value) {
        MapIterator mIter = finder(key);

        if (mIter.isLastEntityInBucket()) {
            return inserter(mIter, new Entry(key, value));
        } else {
            Entry *entry = *(mIter.getBucketIter());

            entry->setValue(value);

            return mIter;
        }
    }

    void erase(K key) {
        MapIterator mIter = finder(key);

        if (mIter.isLastEntityInBucket()) {
            throw NotExistElement("Not Exist Elemet!");
        }

        eraser(mIter);
    }

    void erase(MapIterator iter) {
        eraser(iter);
    }
    
    void printMap() {
        cout << "[ ";
        for (MapIterator mIter = begin(); mIter != end(); ++mIter) {
            cout << **mIter;
            cout << ", ";
        }
        cout << "]" << endl;
    }

private:
    MapIterator finder(K key) {
        int idx = h(key) % bl->size();

        BucketListIterator blIter = bl->begin() + idx;
        Bucket *bucket = *blIter;
        BucketIterator bIter = bucket->begin();

        MapIterator mIter = MapIterator(bl, blIter, bIter);
        Entry *entry = *mIter;
        while (!mIter.isLastEntityInBucket() && entry->getKey() != key) {
            mIter.nextEntry();
        }
        
        return mIter;
    }

    MapIterator inserter(MapIterator mIter, Entry *entry) {
        BucketListIterator blIter = mIter.getBucketListIter();
        BucketIterator bIterAtLast = mIter.getBucketIter();

        Bucket *bucket = *blIter;
        BucketIterator bIterAtTarget = bucket->insert(bIterAtLast, entry);
        size++;

        return MapIterator(bl, blIter, bIterAtTarget);
    }

    void eraser(MapIterator mIter) {
        Bucket *bucket = *(mIter.getBucketListIter());

        bucket->erase(mIter.getBucketIter());
        size--;
    }
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAP_H
