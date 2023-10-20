//
// Created by devan on 9/19/2023.
//

#ifndef WGUCLASS_ROSTER_H
#define WGUCLASS_ROSTER_H
#include <vector>
#include <memory>
#include "Students.h"
using namespace std;
class classRoster {
public:
    static vector<unique_ptr<student>> roster;
    static void add(std::vector<std:: string>& data);
    static void remove(string studentID);
    static void printall();
    static void printInvalidEmails();
    static student parser(string input);
    static void printAverageDaysInCourse(string in);
    static void printByDegreeProgram(degreeprogram in);
};


#endif //WGUCLASS_ROSTER_H
