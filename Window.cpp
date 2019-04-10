#include "Window.h"

Window::Window()
{
  occupied = false;
  idle_time = 0;
  occupied_time = 0;
  student_time_needed = 0;
  curr_student = NULL;
}

void Window::windowCycle()
{
  if(occupied)
  {
    cout << "Occu time: "<< occupied_time << endl;
    if(occupied_time >= student_time_needed)
      removeStudent();
    occupied_time++;
  }
  else
  {
    cout << "Idle time: "<< idle_time << endl;
    idle_time++;
  }
}

void Window::assignStudent(Student s)
{
  curr_student = &s;
  occupied = true;
  idle_time = 0;
  student_time_needed = curr_student->getTimeNeeded();
  cout << "Student with " << student_time_needed << " minutes needed found a window. " << endl;
}

void Window::removeStudent()
{
  cout << "Student " << student_time_needed << " has been removed." << endl;
  curr_student = NULL;
  occupied = false;
  occupied_time = 0;
  student_time_needed = 0;
}
