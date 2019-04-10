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
    if(occupied_time >= student_time_needed)
      removeStudent();
    occupied_time++;
  }
  else
  {
    idle_time++;
  }
}

void Window::assignStudent(Student s)
{
  curr_student = &s;
  occupied = true;
  idle_time = 0;
  student_time_needed = curr_student->getTimeNeeded();
}

void Window::removeStudent()
{
  curr_student = NULL;
  occupied = false;
  occupied_time = 0;
  student_time_needed = 0;
  cout << "A free window has opened up. " << endl;
}
