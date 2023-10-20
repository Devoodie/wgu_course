#include "roster.h"
vector<unique_ptr<student>> classRoster::roster;
int main() {
    cout << "C867-Scripting and programming: Applications"<<endl
         << "Language: C++" << endl <<  "StudentID: 011265847" << endl << "Name: Devante Coley" << endl;
    cout <<endl;
    std::vector<std::string> studentData ={"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                           "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                           "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                           "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                           "A5,Devante,Coley,devantecoley802@gmail.com,22,77,77,77,SOFTWARE"};
    classRoster::add(studentData);
    classRoster::printall();
    classRoster::printInvalidEmails();
    for(int i = 0; i < size(classRoster::roster); ++i){
        student& student = *classRoster::roster[i];
        classRoster::printAverageDaysInCourse(student.getItem("id"));
    }
    cout <<endl;
    classRoster::printByDegreeProgram(SOFTWARE);
    classRoster::remove("A3");
    classRoster::printall();
    classRoster::remove("A3");
    cout << "DONE." <<endl;
    return 0;
}
