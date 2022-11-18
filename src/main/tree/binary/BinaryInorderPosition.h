//
// Created by John on 2022-11-18.
//

#ifndef DATA_STRUCTURE_LECTURE_BINARYINORDERPOSITION_H
#define DATA_STRUCTURE_LECTURE_BINARYINORDERPOSITION_H


#include "BinaryPosition.h"

template <typename E>
class BinaryInorderPosition : public BinaryPosition<E> {
private:
    typedef BinaryPosition<E> Position;
public:
    Position operator++() {
        Position desc = this->getRight();

        if (desc.isInternal()) {
            do {
                this->node = desc.getNode();
                desc = desc.getLeft();
            } while (desc.isInternal());
        } else {
            Position ancestor = this->getParent();

            while (*this == ancestor.getRight()) {
                this->node = ancestor.getNode();
                ancestor = ancestor.getParent();
            }

            this->node = ancestor.getNode();
        }

        return *this;
    }
};

#endif //DATA_STRUCTURE_LECTURE_BINARYINORDERPOSITION_H
