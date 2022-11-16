#ifndef DATA_STRUCTURE_LECTURE_HASHMAPTEST_H
#define DATA_STRUCTURE_LECTURE_HASHMAPTEST_H

#include "../../main/hash/HashMap.h"

using namespace std;

class HashMapTest {
public:
    static void run() {
        HashMap<string, string> map = HashMap<string, string>();

        map.begin();
    }
};

#endif //DATA_STRUCTURE_LECTURE_HASHMAPTEST_H
