//
// Created by devan on 9/19/2023.
//
#include "Students.h"
string items[] = {"id", "name", "email", "age", "major", "average"};
void student::printItem() {
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
int student::itemReturner(std::string& in, std::string arr[]) {
    for (int i = 0; i <= size(items); ++i) {
        if (in == arr[i]) {
            switch (i) {
                case 0:
                    cout << "ID: " + studentID << endl;
                    return i;
                case 1:
                    cout << "NAME: " + firstName + " " + lastname << endl;
                    return i;
                case 2:
                    cout << "EMAIL: " + emailAddress << endl;
                    return i;
                case 3:
                    cout << "AGE: " + to_string(age) << endl;
                    return i;
                case 4:
                    cout << "MAJOR: " + to_string(major) << endl;
                    return i;
                case 5:
                    cout << "Average: "
                         << endl; //Make sure to verify they want the average of the three days or the total.
                    return i;
                default:
                    cout << "Something went wrong!" << endl;
                    return -1;
            }
        }
    }
    return -1;
}
void student::setItem(string& in) {
    string placeholder;
    int index;
    auto check = [](int a) -> bool {
        for (int i = 1; i <= 3; ++i) {
            if (i == a){
                return true;
            }
        }
        return false;
    };
    cout << "Select data to edit from " + firstName + " " + lastname + "! (lowercase only)" << endl;
    for (int i = 0; i <= size(items); ++i) {
        cout << items[i] << endl;
    }
    while(true){
        string userin;
        cin >> userin;
        if(student::inputcheck(in, items)){
            switch(itemReturner(in, items)){
                case 0:
                    cout << "CURRENT ID: " + studentID << endl
                    << "ENTER NEW ID!" << endl;
                    cin >> placeholder;
                    studentID = placeholder;
                    cout << "NEW ID IS: " + studentID << endl;
                    break;
                case 1:
                    cout << "CURRENT NAME: " + firstName + " " + lastname<< endl
                    << "ENTER NEW FIRST NAME!" << endl;
                    cin >> placeholder;
                    firstName = placeholder;
                    cout << "ENTER NEW LAST NAME!" <<endl;
                    cin >> placeholder;
                    lastname = placeholder;
                    cout << "NEW NAME IS: " + firstName + " " +lastname << endl;
                    break;
                case 2:
                    cout << "CURRENT EMAIL: " + emailAddress << endl
                    << "ENTER NEW EMAIL!" << endl;
                    cin >> placeholder;
                    emailAddress = placeholder;
                    cout << "NEW EMAIL IS: " + emailAddress << endl;
                    break;
                case 3:
                    cout << "CURRENT AGE: " + to_string(age) << endl
                    << "ENTER NEW AGE!" << endl;
                    cin >> age;
                    age = stoi(placeholder);
                    cout << "NEW AGE IS: " + to_string(age) << endl;
                    break;
                case 4:
                    cout << "DEGREE PROGRAM: " + to_string(major) << endl << "ENTER NEW DEGREE PROGRAM! (integer)" << endl
                    << "1: SECURITY" << endl << "2: NETWORK" << endl << "3: SOFTWARE" << endl;
                    cin >> placeholder;
                    index = stoi(placeholder);
                    while(true){
                        if (check(index)){
                            cout << "Valid input found!" << endl;
                            major = degreeprogram(index);
                            break;
                        }
                        else{
                            cout << "Please input a valid number: " << endl
                            << "1: SECURITY" << endl << "2: NETWORK" << endl << "3: SOFTWARE" << endl;
                            cin >> placeholder;
                            index = stoi(placeholder);
                        }
                    }
                    cout << "NEW DEGREE PROGRAM IS: " + to_string(major) << endl;
                    break;
                case  5:
                    cout << "Average: " <<endl; //Make sure to verify they want the average of the three days or the total.
                    break;
                default:
                    cout << "Something went wrong!" << endl;
                    break;
            }
            break;
        }
    }
}
string student::getItem(std::string in) {
    if(in == "id"){
        return this->studentID;
    }
    else if(in == "fname"){
        return this->firstName;
    }
    else if(in == "lname"){
        return this->lastname;
    }
    else if(in == "email"){
        return this->emailAddress;
    }
    else if(in == "age"){
        return to_string(this->age);
    }
    else if (in == "major"){
        if(this->major == 1){
            return "SECURITY";
        }
        else if(this->major == 2){
            return "NETWORK";
        }
        else if (this->major)
    }
}


