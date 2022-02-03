#ifndef Roster_H
#define Roster_H
#include "Student.h"


class Roster
{
public: //data members for roster
    int remaining; 
    int numStudents; 
    Student** students; 
    Roster(); //default constructor
    Roster(int headCount); //constructor setting size
    ~Roster(); //deconstructor

    //Methods?
    void parseDataAndAdd(string rawData); //pass raw data to a function
    Degree convert(string str); 
    void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void printAll(); 
    void remove(string studentID); 
    void printAverageDaysInCourse(string studentID); 
    void printInvalidEmails(); 
    void printByDegree(Degree degreeProgram); 

};
#endif