#ifndef DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H

#include "iostream"
#include "CircleList.h"

using namespace std;

class CircularlyLinkedListTest {
public:
    static void run() {
        CircleList playList; // []

        playList.add("Stayin Alive"); // [Stayin Alive*]
        playList.add("Le Freak"); // [Le Freak, Stayin Alive*]
        playList.add("Jive Talkin"); // [Jive Talkin, Le Freak, Stayin Alive*]
        cout << playList.toString() << endl;

        playList.advance(); // [Le Freak, Stayin Alive, Jive Talkin*]
        playList.advance(); // [Stayin Alive, Jive Talkin, Le Freak*]
        cout << playList.toString() << endl;

        playList.remove(); // [Jive Talkin, Le Freak*]
        cout << playList.toString() << endl;

        playList.add("Disco Inferno"); // [Disco Inferno, Jive Talkin, Le Freak*]
        cout << playList.toString() << endl;
    }
};


#endif //DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H
