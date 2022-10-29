#ifndef DATA_STRUCTURE_LECTURE_QUEUEEMPTY_H
#define DATA_STRUCTURE_LECTURE_QUEUEEMPTY_H


#include <exception>

using namespace std;

class QueueEmpty : public exception {
public:
    QueueEmpty(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_QUEUEEMPTY_H
