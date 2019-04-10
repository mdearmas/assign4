/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Window.cpp, contains the out-of-class member functions for Window.
*/
#include "Window.h"

Window::Window() //constructor
{
  occupied = false;
  idle_time = 0;
  occupied_time = 0;
  student_time_needed = 0;
  curr_student = NULL; //no student is assigned initially, so the pointer is NULL
}

void Window::windowCycle() //increments idle_time if not occupied, increments occupied_time if occupied, and removes assigned student if time's up
{
  if(occupied)
  {
    if(occupied_time >= student_time_needed) //if the occupied_time equals the time the student needed at the window, remove the student
      removeStudent();
    occupied_time++; //increment occupied time
  }
  else //window is idle
  {
    idle_time++; //increment idle time
  }
}

void Window::assignStudent(Student s) //assigns the passed student as the student at the window
{
  curr_student = &s;
  occupied = true; //resets bool appropriately
  idle_time = 0; //since window is no longer idle, this goes back down to zero
  student_time_needed = curr_student->getTimeNeeded(); //uses the Student accessor method to store the student's time needed
}

void Window::removeStudent() //removes a student from the window
{
  curr_student = NULL; //nulls the pointer
  occupied = false; //resets the bool appropriately
  occupied_time = 0; //since wndow is no longer occupied, this goes back down to zero
  student_time_needed = 0; //no more student = no more time needed
  cout << "A free window has opened up. " << endl; //prints message to console to inform user of what has occurred
}
