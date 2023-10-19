//
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
                    if (placeholder == "SECURITY") {
                        degree = degreeprogram(1);
                        break;
                    } else if (placeholder == "NETWORK") {
                        degree = degreeprogram(2);
                    } else if (placeholder == "SOFTWARE") {
                        degree = degreeprogram(3);
                        break;
                    } else {
                        placeholder += input[i];
                        break;
                    }
                default:
                    cout << "Something went wrong!" << endl;
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
    for (int i = 0; i < size(classRoster::roster); ++i) {
        student student = *classRoster::roster[i];
        if (student.getItem("id") == studentID) {
            classRoster::roster.erase(classRoster::roster.begin() + i);
            return;
        }
    }
    cout << "No Such Student ID Found!" << endl;
}

void classRoster::printall(){
    string placeholder;
    for(int i = 0; i < size(classRoster::roster); ++i){
        student rosta = *classRoster::roster[i];
        if(rosta.major == 1){
            placeholder = "SECURITY";
        }
        else if(rosta.major == 2){
            placeholder = "NETWORK";
        }
        else if(rosta.major == 3){
            placeholder ="SOFTWARE";
        }
        cout << rosta.studentID + "    First Name: " + rosta.firstName + "     Last Name: "
        + rosta.lastname + "     Age: " + to_string(rosta.age) +"     days in course: " +
        to_string(rosta.daystoComplete[0]) + " " + to_string(rosta.daystoComplete[1]) + " " +
        to_string(rosta.daystoComplete[2]) + " Degree Program: " + placeholder <<endl;
    }
}

void classRoster::printInvalidEmails() {
    for(int i = 0; i < size(classRoster::roster); ++i){
        student& student = *classRoster::roster[i];
        for(int a = 0, ats = 0, dots = 0; a < size(student.getItem("email")); ++a){
            string email = student.getItem("email");
            if(email[a] == ' '){
                cout << student.getItem("id") +  " " + email << endl;
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
                    cout << student.getItem("id") +  " " + email << endl;
                    break;
                }
            }
            if(ats == 1 && dots == 1) {
                break;
            }
        }
    }
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
            check(student.getItem("average"));
        }
    }
}