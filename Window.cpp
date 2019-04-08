#include "Window.h"

Window::Window()
{
  occupied = false;
  idle_time = 0;
  occupied_time = 0;
  curr_student = NULL;
}

void Window::windowCycle()
{
  if(occupied)
    ++occupied_time;
  else
  {
    ++idle_time;
  }
}

void Window::assignStudent(Student s)
{
  curr_student = &s;
  occupied = true;
}

void Window::removeStudent()
{
  curr_student = NULL;
  occupied = false;
  cout << "Student has been removed." << endl;
}
