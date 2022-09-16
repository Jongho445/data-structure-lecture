#ifndef DATA_STRUCTURE_LECTURE_SCORES_H
#define DATA_STRUCTURE_LECTURE_SCORES_H

#include <string>
#include "GameEntry.h"
#include "exception/IndexOutOfBounds.h"

using namespace std;

class Scores {
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i) throw(IndexOutOfBounds);
    void print();
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};


#endif
