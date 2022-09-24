#ifndef DATA_STRUCTURE_LECTURE_STACKFULL_H
#define DATA_STRUCTURE_LECTURE_STACKFULL_H


#include <exception>

using namespace std;

class StackFull : public exception {
public:
    StackFull(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_STACKFULL_H
