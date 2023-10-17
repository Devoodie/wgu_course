#include "roster.h"
vector<unique_ptr<student>> classRoster::roster;
int main() {
    std::vector<std::string> studentData ={"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Devante,Coley,devantecoley802@gmail.com,22,77,77,77,SOFTWARE"};
    std::cout << "Hello, World!" << std::endl;
    classRoster::add(studentData);
    classRoster::printall();
    return 0;
}
