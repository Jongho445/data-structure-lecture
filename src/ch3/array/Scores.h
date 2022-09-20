#ifndef DATA_STRUCTURE_LECTURE_SCORES_H
#define DATA_STRUCTURE_LECTURE_SCORES_H


#include "string"
#include "GameEntry.h"
#include "exception/IndexOutOfBounds.h"

using namespace std;

class Scores {
public:
    Scores(int maxEnt = 10);
    ~Scores();

    void add(const GameEntry& entry);
    GameEntry remove(int i) throw(IndexOutOfBounds);

    string toString();
private:
    int size;
    int length;
    GameEntry* entries;
};


#endif //DATA_STRUCTURE_LECTURE_SCORES_H
