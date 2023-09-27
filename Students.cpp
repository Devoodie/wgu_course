//
// Created by devan on 9/19/2023.
//
#include "main.cpp"
#include "Students.h"
string items[] = {"id", "name", "email", "age", "major", "average"};
void student::getItem() {
    cout << "Select data to fetch from " + firstName + " " + lastname + "! (lowercase only)" << endl;
    for (int i = 0; i <= size(items); ++i) {
        cout << items[i] << endl;
    }
    while(true){
        string userin;
        cin >> userin;
        if(student::inputcheck(userin, items)){
            cout <<
        }
    }
    bool student::inputcheck(std::string& in, std::string arr[]){
        for(int i = 0; i <= 6; ++i) {
            if (in == arr[i]) {
                std::cout << "Valid input found!";
                return true;
            }
        }
        std::cout << "No valid input found!" << std::endl;
        return false;
    }

}

