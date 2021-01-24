//
//  roster.h
//  WGU Final
//
//  Created by Ridge Gleaton on 12/27/20.
//

#ifndef roster_h
#define roster_h
#pragma once
#include "student.h"
#include "degree.h"
using namespace std;

class Roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* studentRosterArray[numStudents];
    
public:

    void parse(string row);
    void add(string sID, string sFname, string sLname, string sEmail, string sAge, double sNumDays1, double sNDays2, double sNDays3, degreeProgram sDegreeProgram);
    void printAll();
    void printByDegreeProgram(degreeProgram sDegreeProgram);
    void printInvalidEmails();
    void printAverageNumDays();
    void removeStudentByID(string studentID);
    
    ~Roster();
    
};

#endif
