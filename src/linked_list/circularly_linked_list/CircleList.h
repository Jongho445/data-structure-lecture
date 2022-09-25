#ifndef DATA_STRUCTURE_LECTURE_CIRCLELIST_H
#define DATA_STRUCTURE_LECTURE_CIRCLELIST_H


#include "CNode.h"

class CircleList {
public:
    CircleList();
    ~CircleList();

    const Elem& front() const;
    const Elem& back() const;

    bool empty() const;

    void advance();

    void add(const Elem& elem);
    void remove();

    string toString();
    string toStringStartsWithCursor();
private:
    CNode* cursor;
};

#endif //DATA_STRUCTURE_LECTURE_CIRCLELIST_H
