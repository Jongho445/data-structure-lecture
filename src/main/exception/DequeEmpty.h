#ifndef DATA_STRUCTURE_LECTURE_DEQUEEMPTY_H
#define DATA_STRUCTURE_LECTURE_DEQUEEMPTY_H


#include "exception"

using namespace std;

class DequeEmpty : public exception {
public:
    DequeEmpty(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_DEQUEEMPTY_H
