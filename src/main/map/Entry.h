#ifndef DATA_STRUCTURE_LECTURE_ENTRY_H
#define DATA_STRUCTURE_LECTURE_ENTRY_H


#include "iostream"

using namespace std;

template <typename K, typename V>
class Entry {
private:
    K key;
    V value;

    bool isEmpty;
public:
    Entry() : isEmpty(true) {}
    Entry(K key, V value) : key(key), value(value), isEmpty(false) {}

    K getKey() { return key; }
    V getValue() { return value; }

    void setKey(K key) { this->key = key; }
    void setValue(V value) { this->value = value; }

    friend ostream &operator <<(ostream &outs, Entry<K, V> entry) {
        if (entry.isEmpty) {
            cout << "{ empty }";
            return outs;
        }

        cout << "{ ";
        cout << entry.key;
        cout << ": ";
        cout << entry.value;
        cout << " }";

        return outs;
    }
};

#endif //DATA_STRUCTURE_LECTURE_ENTRY_H
