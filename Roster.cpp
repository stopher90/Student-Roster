#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

//class constructor
Roster::Roster() 
{
    this->numStudents = 0; 
    this->remaining = -1; 
    this->students = nullptr; 
}
//constructor setting max size.
Roster::Roster(int numStudents) 
{
    this->numStudents = numStudents;
    this->remaining = -1; 
    this->students = new Student * [numStudents]; 
}
Roster::~Roster()//destructor to delete students then roster
{ 
    for (int i = 0; i < numStudents; i++)
    {
        delete this->students[i]; 
    }
    delete this; //removes from memory
}

void Roster::parseDataAndAdd(string rawData)
{ 
    std::vector<string> dataPoints; 
    std::stringstream inputSStream(rawData);

    while (inputSStream.good())//parse's the string at commas
    {
        string data;
        getline(inputSStream, data, ',');
        dataPoints.push_back(data);
    }
    add(dataPoints.at(0), 
        dataPoints.at(1), 
        dataPoints.at(2), 
        dataPoints.at(3), 
        stoi(dataPoints.at(4)), 
        stoi(dataPoints.at(5)), 
        stoi(dataPoints.at(6)), 
        stoi(dataPoints.at(7)), 
        convert(dataPoints.at(8)) 
    );
}
Degree Roster::convert(string str)//converts to an enum
{ 
    if (str == "SECURITY") return SECURITY;
    else if (str == "NETWORK") return NETWORK;
    else if (str == "SOFTWARE") return SOFTWARE;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{ 
    if (remaining < numStudents)//verifies we do not add more than alloted amount
    { 
        remaining++; 
        this->students[remaining] = new Student();
        this->students[remaining]->setStudentID(studentID);
        this->students[remaining]->setFirstName(firstName);
        this->students[remaining]->setLastName(lastName);
        this->students[remaining]->setEmail(emailAddress);
        this->students[remaining]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->students[remaining]->setdaysLeftToComplete(days);
        this->students[remaining]->setDegree(degreeProgram);
    }
    else
    {
        std::cerr << std::endl << "Limit Reached for student roster." << std::endl << std::endl;
    }
}
void Roster::printAll() 
{
    std::cout << "Displaying student roster:" << std::endl << std::endl;
    for (int i = 0; i <= this->remaining; i++)
    {

        (this->students)[i]->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Roster::remove(string studentID)
{ 

    bool found = false; //checks if ID is in the roster

    for (int i = 0; i <= remaining; i++)
    {
        if (this->students[i]->getStudentID() == studentID) 
        {
            found = true; 
            delete this->students[i];
            this->students[i] = this->students[remaining]; 
            remaining--;
            std::cout << "Student removed. " << studentID << std::endl << std::endl;
        }
    }
    if (!found)
    { 
        std::cerr << "Student " << studentID << " does not exist." << std::endl << std::endl;
    }

}
void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false; 

    for (int i = 0; i <= remaining; i++)
    {
        if (this->students[i]->getStudentID() == studentID) 
        {
            found = true;
            int* days = this->students[i]->getdaysLeftToComplete(); 
            int averageDays = static_cast<int>(days[0] + days[1] + days[2]) / 3; 
            std::cout << "Average course completion days for student " << studentID << ", "
                << averageDays << std::endl << std::endl;
        }
    }
    if (!found)
    {
        std::cerr << "Student " << studentID << "does not exist" << std::endl << std::endl;
    }

}
void Roster::printInvalidEmails()
{
    std::cout << "Showing invalid emails:" << std::endl << std::endl;
    bool found = false; 

    for (int i = 0; i <= remaining; i++)
    { 
        string email = this->students[i]->getEmail();//verifies the emails are valid.
        if (
            (email.find('.') == string::npos) || 
            (email.find('@') == string::npos) || 
            !(email.find(' ') == string::npos)   
            )
        { 
            found = true;
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    if (!found)
    {
        std::cout << "None found!" << std::endl << std::endl;
    }
}


