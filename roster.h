//
// Created by devan on 9/19/2023.
//

#ifndef WGUCLASS_ROSTER_H
#define WGUCLASS_ROSTER_H
#include <vector>
#include "Students.h"
using namespace std;
class classRoster {
public:
    static vector<student*> roster;
    static void add(string data[]);
    void remove(string& studentID){};
    void printall();
    void printInvalidEmails();
    static student parser(string input);
};


#endif //WGUCLASS_ROSTER_H
