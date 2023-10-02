//
// Created by devan on 9/19/2023.
//

#ifndef WGUCLASS_STUDENTS_H
#define WGUCLASS_STUDENTS_H
#include <string>
#include <iostream>
using namespace std;
class student {
    string studentID;
    string firstName;
    string lastname;
    string emailAddress;
    unsigned age;
    unsigned daystoComplete[3];
    string degreeProgram;
    student(string sID, string fName, string lName, string email,
             unsigned ayge, unsigned completion[3], string degree) :
            studentID(std::move(sID)), firstName(std::move(fName)), lastname(std::move(lName)),
            emailAddress(std::move(email)),
            age(ayge), daystoComplete{completion[0], completion[1], completion[3]}, degreeProgram(std::move(degree)) {};
    void printItem();
    static bool inputcheck(std::string& in, std::string arr[]);
    void itemReturner(std::string& in, std::string arr[]);
    void setItem();
};
#endif //WGUCLASS_STUDENTS_H
