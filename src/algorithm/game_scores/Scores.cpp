#include "Scores.h"

using namespace std;

Scores::Scores(int maxEnt) {
    size = maxEnt;
    entries = new GameEntry[size];
    length = 0;
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry& e) {
    int newScore = e.score;
    if (length == size) {
        if (newScore <= entries[size - 1].score) return;
    } else {
        length++;
    }

    int i = length - 2;
    while ( i >= 0 && newScore > entries[i].score) {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
    if ((i < 0) || (i >= length)) {
        throw IndexOutOfBounds("Invalid index");
    }

    GameEntry targetElem = entries[i];

    for (; i < length - 1; i++) {
        entries[i] = entries[i + 1];
    }

    entries[length - 1] = GameEntry(); // 맨 뒤의 엔트리 삭제
    length--;

    return targetElem;
}

// DIY
string Scores::toString() {
    string result = "[ ";
    for(int i = 0; i < length; i++) {
        result += entries[i].toString();

        if (i != length - 1) {
            result += ", ";
        } else {
            result += " ]";
        }
    }
    return result;
}
