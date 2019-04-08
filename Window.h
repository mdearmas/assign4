#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>

#include "Student.h"

using namespace std;

class Window {
public:
  Window();

  void windowCycle();
  void assignStudent(Student s);
  void removeStudent();

  bool occupied; //bool to see if a student is currently occupying the window
  int idle_time; //int counting how long this window has been unoccupied
  int occupied_time; //int counting how long a student has been at the window
  Student *curr_student; //pointer to the Student object currently at window
};

#endif
