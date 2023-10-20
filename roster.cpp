
// Created by devan on 9/19/2023.
//
#include "roster.h"
#include <iterator>
#include <memory>
student classRoster::parser(string input) {
    string id;
    string fstname;
    string lstname;
    string email;
    unsigned age;
    string placeholder;
    int completion[3];
    degreeprogram degree;
    int variiter = 0;
    for (int i = 0; i < size(input); ++i) {
        if (input[i] == ',') {
            variiter++;
            placeholder = "";
        } else {
            switch (variiter) {
                case 0:
                    id += input[i];
                    break;
                case 1:
                    fstname += input[i];
                    break;
                case 2:
                    lstname += input[i];
                    break;
                case 3:
                    email += input[i];
                    break;
                case 4:
                    placeholder += input[i];
                    age = stoi(placeholder);
                    break;
                case 5:
                    placeholder += input[i];
                    completion[0] = stoi(placeholder);
                    break;
                case 6:
                    placeholder += input[i];
                    completion[1] = stoi(placeholder);
                    break;
                case 7:
                    placeholder+= input[i];
                    completion[2] = stoi(placeholder);
                    break;
                case 8:
                    placeholder += input[i];
                    if (placeholder == "SECURITY") {
                        degree = SECURITY;
                        break;
                    } else if (placeholder == "NETWORK") {
                        degree = NETWORK;
                    } else if (placeholder == "SOFTWARE") {
                        degree = SOFTWARE;
                        break;
                    }
                    break;
                default:
                    cout << "Something went wrong!" << endl;
                    break;
            }
        }

    }
    return {id,fstname,lstname,email,age,completion,degree};
}

void classRoster::add(std::vector<std:: string>& data){
    for(int i = 0; i < size(data) ; ++i){
        classRoster::roster.push_back(std::make_unique<student>(classRoster::parser(data[i])));
    }
}

void classRoster::remove(string studentID) {
    cout << "Removing " + studentID + "!" << endl;
    for (int i = 0; i < size(classRoster::roster); ++i) {
        student student = *classRoster::roster[i];
        if (student.getItem("id") == studentID) {
            classRoster::roster.erase(classRoster::roster.begin() + i);
            cout << endl;
            return;
        }
    }
    cout << "No Such Student ID Found!" << endl;
    cout << endl;
}

void classRoster::printall(){
    string placeholder;
    cout << "Displaying all students:" << endl;
    for(int i = 0; i < size(classRoster::roster); ++i){
        student rosta = *classRoster::roster[i];
        cout << rosta.getItem("id")+ "    First Name: " + rosta.getItem("fname")+ "     Last Name: "
                +  rosta.getItem("lname") + "     Age: " + rosta.getItem("age") +"     days in course: {" +
                rosta.getItem("average") + "} " + "Degree Program: " + rosta.getItem("major") <<endl;
    }
    cout <<endl;
}

void classRoster::printInvalidEmails() {
    cout << "Displaying Invalid Emails:" <<endl;
    for(int i = 0; i < size(classRoster::roster); ++i){
        student& student = *classRoster::roster[i];
        for(int a = 0, ats = 0, dots = 0; a < size(student.getItem("email")); ++a){
            string email = student.getItem("email");
            if(email[a] == ' '){
                cout << student.getItem("id") +  " " + email + " - is invalid." << endl;
                break;
            }
            else if (email[a] == '@'){
                ats = 1;
                continue;
            }
            else if (email[a] == '.'){
                dots = 1;
                continue;
            }
            else if(a == size(email)-1){
                if(dots != 1 || ats != 1){
                    cout << student.getItem("id") +  " " + email  + " - is inavalid." << endl;
                    break;
                }
            }
            if(ats == 1 && dots == 1) {
                break;
            }
        }
    }
    cout << endl;
}

void classRoster::printAverageDaysInCourse(std::string in) { //this literally makes zero sense just increasing complexity for no reason
    auto check = [](string nums){
        int val1;
        int val2;
        int val3;
        string placeholder;
        for(int i = 0, iter = 0; i < size(nums); ++i){
            if(nums[i] == ','){
                placeholder = "";
                iter++;
                continue;
            }
            else if(iter == 0){
                placeholder += nums[i];
                val1 = stoi(placeholder);
            }
            else if(iter == 1){
                placeholder += nums[i];
                val2 = stoi(placeholder);
            }
            else if(iter == 2){
                placeholder += nums[i];
                val3 = stoi(placeholder);
            }
        }
        cout << (val1 + val2 + val3)/3 <<endl;
    };
    for(int i = 0; i < size(classRoster::roster); ++i){
        student& student = *classRoster::roster[i];
        if(student.getItem("id") == in){
            cout << "Student ID: " + student.getItem("id") + ", average days in course is : ";
            check(student.getItem("average"));
        }
    }
}

void classRoster::printByDegreeProgram(degreeprogram in){
    for(int i = 0 ; i < size(classRoster::roster); ++i){
        student& student = *classRoster::roster[i];
        if(student.getItem("major") == "SOFTWARE" && in == SOFTWARE){
            cout << student.getItem("id")+ "    First Name: " + student.getItem("fname")+ "     Last Name: "
                    +  student.getItem("lname") + "     Age: " + student.getItem("age") +"     days in course: {" +
                    student.getItem("average") + "} " + "Degree Program: " + student.getItem("major") <<endl;
        }
        else if(student.getItem("major") == "NETWORK" && in == NETWORK){
            cout << student.getItem("id")+ "    First Name: " + student.getItem("fname")+ "     Last Name: "
                    +  student.getItem("lname") + "     Age: " + student.getItem("age") +"     days in course: {" +
                    student.getItem("average") + "} " + "Degree Program: " + student.getItem("major") <<endl;
        }
        else if (student.getItem("major") == " SECURITY" && in == SECURITY){
            cout << student.getItem("id")+ "    First Name: " + student.getItem("fname")+ "     Last Name: "
                    +  student.getItem("lname") + "     Age: " + student.getItem("age") +"     days in course: {" +
                    student.getItem("average") + "} " + "Degree Program: " + student.getItem("major") <<endl;
        }
    }
    cout <<endl;
}