#ifndef DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H
#define DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H


template <typename K, typename V>
class HashMapIterator {
private:
    typedef HashMapIterator<K, V> Iterator;
    typedef Entry<K, V> Entry;
    typedef list<Entry> Bucket;

    typedef typename Bucket::iterator BucketIterator;
    typedef typename vector<Bucket>::iterator BucketsIterator;

    vector<Bucket> *buckets;

    BucketIterator bucketIter;
    BucketsIterator bucketsIter;
public:
//    HashMapIterator() : buckets(nullptr), bucketsIter(BucketsIterator()), bucketIter(BucketIterator()) {}
    HashMapIterator(vector<Bucket> *b, BucketsIterator bsi) : buckets(b), bucketsIter(bsi), bucketIter(BucketIterator()) {}
    HashMapIterator(vector<Bucket> *b, BucketsIterator bsi, BucketIterator bi) : buckets(b), bucketsIter(bsi), bucketIter(bi) {}

    Entry operator*() { return *bucketIter; }

    bool operator==(Iterator iter) {
        if (buckets != iter.buckets || bucketsIter != iter.bucketsIter) {
            return false;
        } else if (bucketsIter == buckets->end()) {
            return true;
        }

        return bucketIter == iter.bucketIter;
    }

    Iterator operator++() {
        //다음 Entry로 이동
        ++bucketIter;

        // 이동한 다음 Entry가 end of bucket이라면?
        if (isEndOfBucket()) {
            // 다음 bucket으로 이동
            ++bucketsIter;

            // 해당 bucket이 비어있으면서 마지막 bucket이 아니면 skip
            // -> 해당 bucket이 비어있지 않거나 마지막 bucket이면 not skip(드모르간)
            while ((*bucketsIter).empty() && bucketsIter != buckets->end()) {
                ++bucketsIter;
            }

            // 해당 bucket이 마지막 bucket이 아니라면 Entry를 bucket의 첫 번째 Entry로 초기화
            if (bucketsIter != buckets->end()) {
                bucketIter = (*bucketsIter).begin();
            }
        }

        return *this;
    }

    BucketIterator getBucketIter() { return bucketsIter; }
    BucketsIterator getBucketsIter() { return bucketsIter; }
    vector<Bucket> *getBuckets() { return buckets; };

    void setBucketIter(BucketIterator bucketIter) { this->bucketIter = bucketIter; }
    void setBucketsIter(BucketsIterator bucketsIter) { this->bucketsIter = bucketsIter; }
    void *setBuckets(vector<Bucket> *buckets) { this->buckets = buckets; };
    
protected:
    void nextEntry() { ++bucketIter; }
    
    bool isEndOfBucket() {
        return bucketIter == (*bucketsIter).end();
    }
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H
