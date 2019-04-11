/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Student.cpp, contains the out-of-class member definitions for Student.
*/
#include "Student.h"

Student::Student() //default constructor
{
  //setting to negative prevents any accidental mishaps in the simulation
  arrival_time = -1;
  time_needed = -1;
}

Student::Student(int a, int t) //overloaded constructor, sets arrival_time and time_needed to respective passed parameters
{
  arrival_time = a;
  time_needed = t;
}

Student::Student(const Student& s) //copy constructor
{
  arrival_time = s.arrival_time;
  time_needed = s.time_needed;
}

Student& Student::operator=(const Student &s) //redefines the assignment operator
{
  if(this != &s) //prevents self-assignment
  {
    arrival_time = s.arrival_time;
    time_needed = s.time_needed;
  }
}
