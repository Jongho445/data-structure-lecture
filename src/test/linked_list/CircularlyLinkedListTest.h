#ifndef DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H
#define DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H

#include "iostream"
#include "../../main/linked_list/CircleList.h"

using namespace std;

class CircularlyLinkedListTest {
public:
    static void run() {
        CircleList<string> playList; // []

        playList.add("Stayin Alive"); // [Stayin Alive*]
        cout << playList.toString() << endl;
        playList.add("Le Freak"); // [Le Freak, Stayin Alive*]
        cout << playList.toString() << endl;
        playList.add("Jive Talkin"); // [Jive Talkin, Le Freak, Stayin Alive*]
        cout << playList.toString() + "\n" << endl;

        playList.advance(); // [Le Freak, Stayin Alive, Jive Talkin*]
        playList.advance(); // [Stayin Alive, Jive Talkin, Le Freak*]
        cout << playList.toString() + "\n" << endl;

        playList.remove(); // [Jive Talkin, Le Freak*]
        cout << playList.toString() + "\n" << endl;

        playList.add("Disco Inferno"); // [Disco Inferno, Jive Talkin, Le Freak*]
        cout << playList.toString() + "\n" << endl;
    }
};


#endif //DATA_STRUCTURE_LECTURE_CIRCULARLYLINKEDLISTTEST_H
