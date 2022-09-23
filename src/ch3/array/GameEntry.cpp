#include "GameEntry.h"

GameEntry::GameEntry(const string& n, int s): name(n), score(s) {}

string GameEntry::toString() {
    return "{ name: " + name + ", score: " + to_string(score) + " }";
}
