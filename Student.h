/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Student.h, contains the class definition for Student. Student class contains variables to
  store both the student's planned arrival time to the registrar and the time they will spend at a window.
*/
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

using namespace std;

class Student {
public:
  Student(); //default constructor
  Student(int a, int t); //overloaded constructor
  Student(const Student& s); //copy constructor

  int getArrivalTime() { return arrival_time; } //accessor for the student's arrival_time
  int getTimeNeeded() { return time_needed; } //accessor for the student's time_needed

  Student& operator=(const Student &s); //redefines the assignment operator

private:
  int arrival_time; //int marking what minute the student will arrive
  int time_needed; //int keeping track of how long a student needs at a window
};

#endif
