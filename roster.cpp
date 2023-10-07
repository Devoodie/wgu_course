//
// Created by devan on 9/19/2023.
//
#include "Students.h"
#include "roster.h"
#include <memory>
void add(std::string data[]){
    std::unique_ptr<student> a;
    for(auto i = data->begin(); i != data->end(); ++i){

    }

};
void remove(std::string& studentID){

};
student parser(string& input){
    string id;
    string fstname;
    string lstname;
    string email;
    unsigned age;
    string ageplaceholder;
    unsigned completion[3];
    string complplaceholder;
    degreeprogram degree;
    int variiter = 0;
    for (int i = 0; i <= size(input); ++i){
        if(input[i] == ','){
            variiter++;
        }
        else{
            switch(variiter){
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
                    ageplaceholder += input[i];
                    age = stoi(ageplaceholder);
                    break;
                case 5:
                    complplaceholder += input[i];
                    completion[0] = stoi(complplaceholder);
            }
        }

    }
}

