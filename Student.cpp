#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "Degree.h"
using std::cout;
using std::left;
using std::setw;


Student::Student()//default constructor for student class
{
    this->studentID = "";
    this->fName = "";
    this->lName = "";
    this->email = "";
    this->age = -1;
    for (int i = 0; i < courseArray; i++)
    {
        this->daysInCourse[i] = 0;
    }
   
} 

//true constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysLeftToComplete[], Degree degreeProgram)
{
    this->studentID = studentID;
    this->fName = firstName;
    this->lName = lastName;
    this->email = emailAddress;
    this->age = age;
    for (int i = 0; i < courseArray; i++)
    {
        this->daysInCourse[i] = daysLeftToComplete[i];
    }
    this->degreeProgram = degreeProgram;
} 

Student::~Student() //destructor
{
}

//these are the getters
string Student::getStudentID() const
{
    return studentID;
}
string Student::getFirstName() const
{
    return fName;
}
string Student::getLastName() const
{
    return lName;
}
string Student::getEmail() const
{
    return email;
}
int Student::getAge() const
{
    return age;
}
int* Student::getdaysLeftToComplete()
{
    return daysInCourse;
}
Degree Student::getDegree() const {
    return degreeProgram;
}

//these are the setters
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->fName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lName = lastName;
}
void Student::setEmail(string emailAddress)
{
    this->email = emailAddress;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setdaysLeftToComplete(int daysLeftToComplete[])
{
    for (int i = 0; i < courseArray; i++)
    {
        this->daysInCourse[i] = daysLeftToComplete[i];
    }
}
void Student::setDegree(Degree program) {
    this->degreeProgram = program;
}

//methods also
void Student::print()
{ 
    cout << studentID << "\t"
        << "First Name: " << fName << "\t"
        << "Last Name: " << lName << "\t"
        << "Age: " << age << "\t"
        << "daysInCourse: {" << daysInCourse[0] << ", "
        << daysInCourse[1] << ", "
        << daysInCourse[2] << "} "
        << "Degree Program: " << degreePrograms[getDegree()];
}