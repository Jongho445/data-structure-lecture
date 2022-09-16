#ifndef DATA_STRUCTURE_LECTURE_ARRAYTEST_H
#define DATA_STRUCTURE_LECTURE_ARRAYTEST_H

#include "Scores.h"

class ArrayTest {
public:
    static void run() {
        Scores *scores = new Scores(5);

        const GameEntry &entry1 = GameEntry("john", 65);
        const GameEntry &entry2 = GameEntry("peter", 80);
        const GameEntry &entry3 = GameEntry("kim", 70);
        const GameEntry &entry4 = GameEntry("park", 90);

        scores->add(entry1);
        scores->add(entry2);
        scores->add(entry3);
        scores->add(entry4);
        scores->print();

        scores->remove(1);
        scores->print();
    };
};

#endif
