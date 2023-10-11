//
// Created by devan on 9/19/2023.
//
#include "roster.h"
#include <memory>
#include <iterator>
student classRoster::parser(string input) {
    string id;
    string fstname;
    string lstname;
    string email;
    unsigned age;
    string placeholder;
    unsigned completion[3];
    degreeprogram degree;
    int variiter = 0;
    for (int i = 0; i <= size(input); ++i) {
        cout << i << endl;
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
void classRoster::add(std::string data[]){
    for(int i = 0; i <= data->size() ; ++i){
        classRoster::roster.push_back(new student(classRoster::parser(data[i])));
        cout << classRoster::roster[0] << endl;
    }
}

