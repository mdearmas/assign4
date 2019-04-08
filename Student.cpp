#include "Student.h"

Student::Student()
{
  arrival_time = 0;
  wait_time = 0;
  time_needed = 0;
}

Student::Student(int a, int w, int t)
{
  arrival_time = a;
  wait_time = w;
  time_needed = t;
}

void Student::studentCycle()
{
  ++wait_time;
}
