#include "Student.h"

Student::Student()
{
  arrival_time = 0;
  time_needed = 0;
}

Student::Student(int a, int t)
{
  arrival_time = a;
  time_needed = t;
}

Student::Student(const Student& s)
{
  arrival_time = s.arrival_time;
  time_needed = s.time_needed;
}

Student& Student::operator=(const Student &s)
{
  if(this != &s)
  {
    arrival_time = s.arrival_time;
    time_needed = s.time_needed;
  }
}
