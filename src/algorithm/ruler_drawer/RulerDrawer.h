#ifndef DATA_STRUCTURE_LECTURE_RULERDRAWER_H
#define DATA_STRUCTURE_LECTURE_RULERDRAWER_H


class RulerDrawer {
public:
    void drawRuler(int nInches, int majorLength);
private:
    void drawOneTick(int tickLength, int tickLabel = -1);
    void drawTicks(int tickLength);
};


#endif //DATA_STRUCTURE_LECTURE_RULERDRAWER_H
