#ifndef DATA_STRUCTURE_LECTURE_STACKEMPTY_H
#define DATA_STRUCTURE_LECTURE_STACKEMPTY_H


#include <exception>

using namespace std;

class StackEmpty : public exception {
public:
    StackEmpty(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_STACKEMPTY_H
