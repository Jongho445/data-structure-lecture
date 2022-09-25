#include "iostream"
#include "RulerDrawer.h"

using namespace std;

void RulerDrawer::drawRuler(int nInches, int majorLength) {

    drawOneTick(majorLength, 0);

    for (int i = 1; i <= nInches; i++) {
        drawTicks(majorLength-1);

        drawOneTick(majorLength, i);
    }
}

void RulerDrawer::drawTicks(int tickLength) {
    if (tickLength <= 0) {
        return;
    }

    drawTicks(tickLength-1);

    drawOneTick(tickLength);

    drawTicks(tickLength-1);
}

void RulerDrawer::drawOneTick(int tickLength, int tickLabel) {
    for (int i = 0; i < tickLength; i++) {
        cout << "-";
    }

    if (tickLabel >= 0) {
        cout << " " << tickLabel;
    }

    cout << "\n";
}