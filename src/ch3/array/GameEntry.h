#ifndef DATA_STRUCTURE_LECTURE_GAMEENTRY_H
#define DATA_STRUCTURE_LECTURE_GAMEENTRY_H


#include "string"

using namespace std;

class GameEntry {
public:
    GameEntry(const string& n="", int s=0);

    string toString();
private:
    string name;
    int score;

    friend class Scores;
};


#endif //DATA_STRUCTURE_LECTURE_GAMEENTRY_H
