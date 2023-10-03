//
// Created by devan on 9/19/2023.
//

#ifndef WGUCLASS_ROSTER_H
#define WGUCLASS_ROSTER_H
#include <vector>
#include "students.h"
#include "degree.h"
using namespace std;
class classRoster {
    vector<student*> roster;
    classRoster() : roster({}) {};
public:
    void add(string& studentID, string& firstName, string& lastName, string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeprogram degreeprogram){};
    void remove(string& studentID){};
    void printall();
    void printInvalidEmails();
};


#endif //WGUCLASS_ROSTER_H
