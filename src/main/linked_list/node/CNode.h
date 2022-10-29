#ifndef DATA_STRUCTURE_LECTURE_CNODE_H
#define DATA_STRUCTURE_LECTURE_CNODE_H


#include "string"

using namespace std;

typedef string Elem;

class CNode {
public:
    CNode(): next(nullptr) {}

    string toString() {
        if (next != nullptr) {
            return "{ elem: \"" + elem
                   + "\", next: " + toString(next) + " }";
        }

        return "null";
    }
    string toString(CNode *node) {
        string result = node->elem;

        if (result.empty()) {
            return "\"\"";
        }

        return "\"" + result + "\"";
    }
private:
    Elem elem;
    CNode* next;

    friend class CircleList;
};


#endif //DATA_STRUCTURE_LECTURE_CNODE_H
