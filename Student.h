#ifndef Student_H
#define Student_H
#include "Degree.h"

class Student
{

public: 
    const static int courseArray = 3; //declaring size
    Student(); //default constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, 
        int age, int daysLeftToComplete[], Degree degreeProgram); //constructor
    ~Student();//deconstructor
    
    //getters
    string getStudentID() const; 
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getdaysLeftToComplete();
    Degree getDegree() const;

    //setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setdaysLeftToComplete(int daysLeftToComplete[]);
    void setDegree(Degree degreeProgram);

    void print();//this is a method

    //private data members that only setters can modify
private:
    string studentID;
    string fName;
    string lName;
    string email;
    int age;
    int daysInCourse[courseArray]; 
    Degree degreeProgram;
};
#endif