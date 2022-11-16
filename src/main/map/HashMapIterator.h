#ifndef DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H
#define DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H


template <typename K, typename V>
class HashMapIterator {
private:
    typedef HashMapIterator<K, V> MapIterator;
    typedef Entry<K, V> Entry;
    typedef list<Entry*> Bucket;
    typedef vector<Bucket*> BucketList;
    typedef typename Bucket::iterator BucketIterator;
    typedef typename BucketList::iterator BucketListIterator;

    BucketList *bl;

    BucketIterator bIter;
    BucketListIterator blIter;
public:
    HashMapIterator(BucketList *bl, BucketListIterator blIter) : bl(bl), blIter(blIter), bIter(BucketIterator()) {}
    HashMapIterator(BucketList *bl, BucketListIterator blIter, BucketIterator bIter) : bl(bl), blIter(blIter), bIter(bIter) {}

    Entry *operator*() { return *bIter; }

    bool operator==(MapIterator mIter) {
        if (isEnd() == mIter.isEnd()) {
            return true;
        }

        if (bl != mIter.bl || blIter != mIter.blIter) {
            return false;
        }

        return bIter == mIter.bIter;
    }

    bool operator!=(MapIterator mIter) { return !operator==(mIter); }

    MapIterator operator++() {
        //다음 Entry로 이동
        ++bIter;

        // 이동한 다음 Entry가 end of bucket이라면?
        if (isLastEntityInBucket()) {
            // 다음 bucket으로 이동
            ++blIter;

            // 해당 bucket이 비어있으면서 마지막 bucket이 아니면 skip
            // -> 해당 bucket이 비어있지 않거나 마지막 bucket이면 not skip(드모르간)
            // 참고로 순서를 (*blIter)->empty() && blIter != bl->end()로 하면 end 이터레이터의 operator*를 호출하기에 에러남
            while (blIter != bl->end() && (*blIter)->empty()) {
                ++blIter;
            }

            // 해당 bucket이 마지막 bucket이 아니라면 Entry를 bucket의 첫 번째 Entry로 초기화
            if (blIter != bl->end()) {
                bIter = (*blIter)->begin();
            }
        }

        return *this;
    }

    bool isLastEntityInBucket() {
        Bucket *bucket = *blIter;

        return bIter == bucket->end();
    }

    void nextEntry() {
        ++bIter;
    }

    BucketIterator getBucketIter() { return bIter; }
    BucketListIterator getBucketListIter() { return blIter; }

protected:
    bool isEnd() {
        return blIter == bl->end();
    }
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H
