#include <iostream>
#include "Scores.h"
#include "exception/IndexOutOfBounds.h"

using namespace std;

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries - 1].getScore()) return;
    } else {
        numEntries++;
    }

    int i = numEntries - 2;
    while ( i >= 0 && newScore > entries[i].getScore() ) {
        entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
    if ((i < 0) || (i >= numEntries)) {
        throw IndexOutOfBounds("Invalid index");
    }

    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++) {
        entries[j - 1] = entries[j];
    }
    numEntries--;

    entries[numEntries] = GameEntry(); // 마지막 남은 엔트리 삭제

    return e;
}

void Scores::print() {
    cout << "start print" << endl;
    for(int i = 0; i < maxEntries; i++) {
        cout << "name: " << entries[i].getName()
             << " score: " << entries[i].getScore() << endl;
    }
}
