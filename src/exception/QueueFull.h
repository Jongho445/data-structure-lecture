#ifndef DATA_STRUCTURE_LECTURE_QUEUEFULL_H
#define DATA_STRUCTURE_LECTURE_QUEUEFULL_H


#include <exception>

using namespace std;

class QueueFull : public exception {
public:
    QueueFull(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_QUEUEFULL_H
