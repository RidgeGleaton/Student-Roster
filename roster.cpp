//
//  roster.cpp
//  WGU Final
//
//  Created by Ridge Gleaton on 12/27/20.
//
#ifndef roster_cpp
#define roster_cpp
#include <stdio.h>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;



//PARSING THE ROSTER
void Roster::parse(string studentData)
{
    degreeProgram degree = SOFTWARE;
    if (studentData.back() == 'K') degree = NETWORK;
    else if (studentData.back() == 'Y') degree = SECURITY;

    
    
    int rhs = studentData.find(",");
    string sID = studentData.substr(0,rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fn = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string ln = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string em = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string ageN = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double nd1 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double nd2 = stod(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    double nd3 = stod(studentData.substr(lhs, rhs - lhs));
    
    add(sID, fn, ln, em, ageN, nd1, nd2, nd3, degree);
    
}





//UPDATE ROSTER
void Roster::add(string sID, string sFname, string sLname, string sEmail, string sAge, double sNumDays1, double sNumDays2, double sNumDays3, degreeProgram sDegreeProgram)
{
    double ndarray[3] = { sNumDays1,sNumDays2,sNumDays3 };
    
    studentRosterArray[++lastIndex] = new Student(sID, sFname, sLname, sEmail, sAge, ndarray, sDegreeProgram);
}





//PRINT ALL
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << studentRosterArray[i]->getID(); cout << '\t';
        cout << studentRosterArray[i]->getFName(); cout << '\t';
        cout << studentRosterArray[i]->getLName(); cout << '\t';
        cout << studentRosterArray[i]->getEmailaddress(); cout << '\t';
        cout << studentRosterArray[i]->getAge(); cout << '\t';
        cout << studentRosterArray[i]->getNDays()[0]; cout << '\t';
        cout << studentRosterArray[i]->getNDays()[1]; cout << '\t';
        cout << studentRosterArray[i]->getNDays()[2]; cout << '\t';
        cout << degreeProgramStrings[studentRosterArray[i]->getdegreeprogram()] << std::endl;
    }
}





//PRINT BY DEGREE TYPE
void Roster::printByDegreeProgram(degreeProgram degree)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::studentRosterArray[i]->getdegreeprogram() == degree) studentRosterArray[i]->print();
    }
    cout << std::endl;
}





//PRINT INVALID EMAILS
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string emadd = (studentRosterArray[i]->getEmailaddress());
        if (emadd.find('@') == string::npos || (emadd.find('.') == string::npos || (emadd.find(' ') != string::npos)))
        {
            any = true;
            cout << emadd << ": " << studentRosterArray[i]->getFName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}





//PRINT AVERAGE NUMBER OF DAYS IN COURSES
void Roster::printAverageNumDays()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << studentRosterArray[i]->getID() << ": ";
        cout << (studentRosterArray[i]->getNDays()[0] + studentRosterArray[i]->getNDays()[1] + studentRosterArray[i]->getNDays()[2])/3.0 << std::endl;
    }
    cout << std::endl;
}





//REMOVE VIA STUDENT ID
void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (studentRosterArray[i]->getID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = studentRosterArray[i];
                studentRosterArray[i] = studentRosterArray[numStudents - 1];
                studentRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " was removed from the roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " was not found." << std::endl << std::endl;
}




//DESTRUCTOR
Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
        
    }
}

#endif
