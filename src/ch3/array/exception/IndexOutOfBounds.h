#ifndef DATA_STRUCTURE_LECTURE_INDEXOUTOFBOUNDS_H
#define DATA_STRUCTURE_LECTURE_INDEXOUTOFBOUNDS_H

#include <exception>
#include <string>

using namespace std;

class IndexOutOfBounds : public exception {
public:
    IndexOutOfBounds(const char *string): msg(string) {};

    const char * what() const noexcept override {
        return msg;
    }

private:
    const char *msg;
};


#endif //DATA_STRUCTURE_LECTURE_INDEXOUTOFBOUNDS_H
