//
//  student.h
//  WGU Final
//
//  Created by Ridge Gleaton on 12/27/20.
//
#ifndef student_h
#define student_h
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
#include <string>
using namespace std;

class Student {

public:

    const static int numDaysArraySize = 3;

private:

    string studentID;
    string firstName;
    string lastName;
    string email;
    string age;
    double numDays[numDaysArraySize];
    degreeProgram degreeprogram;

public:

    Student();
    Student(string studentID, string firstName, string lastName, string email, string age, double numDays[], degreeProgram degreeprogram);
    ~Student();

//ACCESSORS

    string getID();
    string getFName();
    string getLName();
    string getEmailaddress();
    string getAge();
    double* getNDays();
    degreeProgram getdegreeprogram();

//MUTATORS

    void setID(string ID);
    void setFName(string fname);
    void setLName(string lname);
    void setEmailaddress(string emailaddress);
    void setnewAge(string newage);
    void setNDays(double ndays[]);
    void setdegreeProgram(degreeProgram degree);

    static void printHeader();

    void print();

    

};


#endif
