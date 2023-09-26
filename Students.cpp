//
// Created by devan on 9/19/2023.
//
#include "main.cpp"
#include "Students.h"
void student::getItem() {
    cout << "Select data to fetch from " + firstName + " " + lastname + "! (lowercase only)" << endl;
    for (int i = 0; i <= size(items); ++i) {
        cout << items[i] << endl;
    }
}