#include "GameEntry.h"

GameEntry::GameEntry(const string& n, int s): name(n), score(s) {}

string GameEntry::toString() {
    return "{ getName: " + name + ", score: " + to_string(score) + " }";
}
