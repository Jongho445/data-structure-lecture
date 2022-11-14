#ifndef DATA_STRUCTURE_LECTURE_BOUNDARYVIOLATION_H
#define DATA_STRUCTURE_LECTURE_BOUNDARYVIOLATION_H


#include <exception>

using namespace std;

class BoundaryViolation : public exception {
public:
    BoundaryViolation(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_BOUNDARYVIOLATION_H
