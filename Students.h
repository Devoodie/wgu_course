//
// Created by devan on 9/19/2023.
//

#ifndef WGUCLASS_STUDENTS_H
#define WGUCLASS_STUDENTS_H
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;
class student {
public:
    student(string sID, string fName, string lName, string email,
            unsigned ayge, int completion[3], degreeprogram degree) :
            studentID(std::move(sID)), firstName(std::move(fName)), lastname(std::move(lName)),
            emailAddress(std::move(email)),
            age(ayge), daystoComplete{completion[0], completion[1], completion[2]}, major(degree) {};
    string studentID;
    string firstName;
    string lastname;
    string emailAddress;
    unsigned age;
    int daystoComplete[3];
    degreeprogram major;
    void printItem();
    static bool inputcheck(std::string& in, std::string arr[]);
    int itemReturner(std::string& in, std::string arr[]);
    void setItem(string& in);
    string getItem(string in);
};
#endif //WGUCLASS_STUDENTS_H
