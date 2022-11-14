#ifndef DATA_STRUCTURE_LECTURE_NOTEXISTELEMENT_H
#define DATA_STRUCTURE_LECTURE_NOTEXISTELEMENT_H


#include <exception>

using namespace std;

class NotExistElement : public exception {
public:
    NotExistElement(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};

#endif //DATA_STRUCTURE_LECTURE_NOTEXISTELEMENT_H
