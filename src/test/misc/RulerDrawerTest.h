#ifndef DATA_STRUCTURE_LECTURE_RULERDRAWERTEST_H
#define DATA_STRUCTURE_LECTURE_RULERDRAWERTEST_H


#include "../../main/misc/ruler_drawer/RulerDrawer.h"

class RulerDrawerTest {
public:
    static void run() {
        RulerDrawer drawer;

        drawer.drawRuler(2,4);
    }
};

#endif //DATA_STRUCTURE_LECTURE_RULERDRAWERTEST_H
