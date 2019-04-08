#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

using namespace std;

class Student {
public:
  Student();
  Student(int a, int w, int t);

  void studentCycle();

  int arrival_time; //int marking what minute the student will arrive
  int wait_time; //int counting how long the student has been in the queue
  int time_needed; //int keeping track of how long a student needs at a window
};

#endif
