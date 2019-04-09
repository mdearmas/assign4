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
  {
    ++occupied_time;
    if(occupied_time == curr_student->time_needed)
      removeStudent();
  }
  else
  {
    ++idle_time;
  }
}

void Window::assignStudent(Student s)
{
  curr_student = &s;
  occupied = true;
  cout << "Student with " << curr_student->time_needed << " minutes needed found a window. " << endl;
}

void Window::removeStudent()
{
  curr_student = NULL;
  occupied = false;
  cout << "Student has been removed." << endl;
}
