#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

using namespace std;

class Student {
public:
  Student();
  Student(int a, int t);
  Student(const Student& s);

  int arrival_time; //int marking what minute the student will arrive
  int time_needed; //int keeping track of how long a student needs at a window

  Student& operator=(const Student &s); //redefines the assignment operator
};

#endif
