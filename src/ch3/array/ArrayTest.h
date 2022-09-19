#ifndef DATA_STRUCTURE_LECTURE_ARRAYTEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYTEST_H


#include "Scores.h"
#include "iostream"

using namespace std;

class ArrayTest {
public:
    static void run() {
        // given
        Scores *scores = new Scores(5);
        const GameEntry &entry1 = GameEntry("john", 65);
        const GameEntry &entry2 = GameEntry("peter", 80);
        const GameEntry &entry3 = GameEntry("kim", 70);
        const GameEntry &entry4 = GameEntry("park", 90);

        // when adding 4 elems
        scores->add(entry1);
        scores->add(entry2);
        scores->add(entry3);
        scores->add(entry4);

        // then
        cout << scores->toString() << endl;

        // when removing scores[1] elem
        scores->remove(1);

        // then
        cout << scores->toString() << endl;
    };
};


#endif //DATA_STRUCTURE_LECTURE_ARRAYTEST_H
