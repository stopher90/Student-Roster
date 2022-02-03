#include <iostream>
#include <iomanip>
#include "Roster.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;

int main() {

    //data string to be parsed
    const string studentData[] = { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Christopher,DuPont,cdupont@dwgu.edu,31,1,30,30,SOFTWARE"
    };

   //Requested information
    cout << left << setw(55) << "Scripting and Programming Applications";
    cout << left << setw(8) << "C++";
    cout << left << setw(12) << "001693730";
    cout << left << setw(15) << "Christopher DuPont";
    cout << endl;
    

    Roster* classRoster = new Roster(5); 
    //adding students to the roster until limit is reached
    for (int i = 0; i < 5; i++)
    { 
        classRoster->parseDataAndAdd(studentData[i]);

    }

    //psuedo code provided
    classRoster->printAll();
    classRoster->printInvalidEmails();
    
    //A loop for the array and each element
    for (int i = 0; i < classRoster->numStudents; i++)
    {
        classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID());
    }
    
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
   // after student is removed a diplay message will appear.

    return 0;
}