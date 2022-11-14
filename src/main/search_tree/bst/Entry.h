#ifndef DATA_STRUCTURE_LECTURE_ENTRY_H
#define DATA_STRUCTURE_LECTURE_ENTRY_H

template <typename K, typename V>
class Entry {
public:
    Entry(K key, V value): key(key), value(value) {}

    K getKey() { return key; }
    V getValue() {return value; }

    void setKey(K key) { this->key = key; }
    void setValue(K value) { this->value = value; }

private:
    K key;
    V value;
};

#endif //DATA_STRUCTURE_LECTURE_ENTRY_H
