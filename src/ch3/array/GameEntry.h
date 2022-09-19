#ifndef DATA_STRUCTURE_LECTURE_GAMEENTRY_H
#define DATA_STRUCTURE_LECTURE_GAMEENTRY_H


#include "string"

using namespace std;

class GameEntry {
public:
    GameEntry(const string& n="", int s=0);

    string getName() const;
    int getScore() const;

    string toString();
private:
    string name;
    int score;
};


#endif //DATA_STRUCTURE_LECTURE_GAMEENTRY_H
