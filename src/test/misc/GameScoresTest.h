#ifndef DATA_STRUCTURE_LECTURE_GAMESCORESTEST_H
#define DATA_STRUCTURE_LECTURE_GAMESCORESTEST_H


#include "../../main/misc/game_score/Scores.h"
#include "iostream"

using namespace std;

class GameScoresTest {
public:
    static void run() {
        // given
        Scores scores = Scores(5);

        scores.add(GameEntry("john", 65));
        scores.add(GameEntry("peter", 80));
        scores.add(GameEntry("kim", 70));
        scores.add(GameEntry("park", 90));
        scores.add(GameEntry("lee", 97));
        scores.add(GameEntry("jane", 95));

        cout << scores.toString() << endl;

        // when: remove scores[1]
        scores.remove(1);

        // then
        cout << scores.toString() << endl;
    };
};


#endif //DATA_STRUCTURE_LECTURE_GAMESCORESTEST_H
