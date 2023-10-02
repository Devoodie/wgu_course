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
            itemReturner(userin, items);
            break;
        }
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
void student::itemReturner(std::string& in, std::string arr[]) {
    for(int i = 0; i <= size(items); ++i){
        if (in == arr[i]){
            switch (i){
                case 0:
                    cout << "ID: " + studentID << endl;
                    break;
                case 1:
                    cout << "NAME: " + firstName + " " + lastname <<endl;
                    break;
                case 2:
                    cout << "EMAIL: " + emailAddress << endl;
                    break;
                case 3:
                    cout << "AGE: " + to_string(age) << endl;
                    break;
                case 4:
                    cout << "MAJOR: " + degreeProgram << endl;
                    break;
                case  5:
                    cout << "Average: " <<endl; //Make sure to verify they want the average of the three days or the total.
                    break;
                default:
                    cout << "Something went wrong!" << endl;
                    break;
            }
        }

    }

}

