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

    BucketIterator bucketIter;
    BucketsIterator bucketsIter;

    vector<Bucket> *buckets;
public:
    HashMapIterator(BucketIterator bi, BucketsIterator bsi, vector<Bucket> *b) : bucketIter(bi), bucketsIter(bsi), buckets(b) {}

    Entry operator*() {}

    bool operator==(Iterator iter) {}

    Iterator operator++() {}

    BucketIterator getBucketIter() { return bucketsIter; }
    BucketsIterator getBucketsIter() { return bucketsIter; }
    vector<Bucket> *getBuckets() { return buckets; };

    void setBucketIter(BucketIterator bucketIter) { this->bucketIter = bucketIter; }
    void setBucketsIter(BucketsIterator bucketsIter) { this->bucketsIter = bucketsIter; }
    void *setBuckets(vector<Bucket> *buckets) { this->buckets = buckets; };
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAPITERATOR_H
