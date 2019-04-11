/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Window.h, contains the definition for the Window class. The class includes a bool to indicate if it's occupied,
  ints to keep track of both the Window's time occupied by a student and its idle time, a pointer to a student currently at the window,
  and an int to store said student's time needed at the window (to avoid any errors with pointer assignment)
*/
#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>

#include "Student.h"

using namespace std;

class Window {
public:
  Window(); //constructor

  void windowCycle(); //represents the passing of time: increments idle_time if not occupied, increments occupied_time if occupied, and removes assigned student if time's up
  void assignStudent(Student s); //assigns a student to the window
  void removeStudent(); //removes a student from a window

  //accessor methods
  bool isOccupied() { return occupied; }
  int getIdleTime() { return idle_time; }
  int getStudentTime() { return student_time_needed; }

private:
  bool occupied; //bool to see if a student is currently occupying the window
  int idle_time; //int counting how long this window has been unoccupied
  int occupied_time; //int counting how long a student has been at the window
  int student_time_needed; //int to hold the amount of time the current student at the window needs
  Student *curr_student; //pointer to the Student object currently at window
};

#endif
