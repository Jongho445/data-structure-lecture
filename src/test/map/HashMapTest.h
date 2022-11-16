#ifndef DATA_STRUCTURE_LECTURE_HASHMAPTEST_H
#define DATA_STRUCTURE_LECTURE_HASHMAPTEST_H

#include "../../main/map/HashMap.h"

using namespace std;

class HashMapTest {
public:
    static void run() {
        HashMap<string, string> map = HashMap<string, string>(3);

        map.put("12", "hello");
        map.put("20", "haha");
        map.printMap();

        typedef HashMapIterator<string, string> MapIterator;
        MapIterator mIter = map.find("12");
        cout << **mIter << endl;

        map.erase("12");
        map.printMap();
    }
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAPTEST_H
