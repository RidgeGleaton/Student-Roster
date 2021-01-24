//
//  student.cpp
//  WGU Final
//
//  Created by Ridge Gleaton on 12/27/20.
//
#ifndef student_cpp
#define student_cpp
#include <stdio.h>
#include <iostream>
#include "student.h"
#include <string>

Student::Student()

{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = "";
    for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = 0;
    this->degreeprogram = degreeProgram::SOFTWARE;

}

Student::Student(string studentID, string firstName, string lastName, string email, string age, double numDays[], degreeProgram degreeprogram)

{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = numDays[i];
    this->degreeprogram = degreeprogram;
}

Student::~Student() {}


string Student::getID() { return this->studentID; }
string Student::getFName() { return this->firstName; }
string Student::getLName() { return this->lastName; }
string Student::getEmailaddress() { return this->email; }
string Student::getAge() { return this->age; }
double* Student::getNDays() { return this->numDays; }
degreeProgram Student::getdegreeprogram() { return this->degreeprogram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFName(string fname) { this->firstName = fname; }
void Student::setLName(string lname) { this->lastName = lname; }
void Student::setEmailaddress(string emailaddress) { this->email = emailaddress; }
void Student::setnewAge(string newage) { this->age = newage; }
void Student::setNDays(double ndays[])
{
    for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = numDays[i];
}
void Student::setdegreeProgram(degreeProgram degree) { this->degreeprogram = degree; }



void Student::printHeader()
{
    cout << "ID | First Name | Last Name | Email | Age | Days in Courses\n";
}

void Student::print()
{
    cout << this->getID() << '\t';
    cout << this->getFName() << '\t';
    cout << this->getLName() << '\t';
    cout << this->getEmailaddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getNDays()[0] << ',';
    cout << this->getNDays()[1] << ',';
    cout << this->getNDays()[2] << '\t';
    cout << degreeProgramStrings[this->getdegreeprogram()] << '\n';

}

#endif
