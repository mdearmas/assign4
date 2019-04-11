/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Registrar.cpp, contains the out-of-class member functions for Registrar.
*/
#include "Registrar.h"

Registrar::Registrar() //default constructor
{
  window_array = new Window[5]; //defaults to an array of 5 windows
  window_array_size = 5;
  waiting_students = new GenQueue<Student>();

  window_idles = new TimeCollector();
  student_waits = new TimeCollector();
}

Registrar::Registrar(int w) //overloaded constructor, makes the window array the size of the passed parameter
{
  window_array = new Window[w];
  window_array_size = w;
  waiting_students = new GenQueue<Student>();

  window_idles = new TimeCollector();
  student_waits = new TimeCollector();
}

Registrar::~Registrar() //destructor
{
  delete[] window_array; //deallocates array
  delete waiting_students;
  delete window_idles;
  delete student_waits;
}

bool Registrar::allWindowsEmpty() //returns true if all the windows are empty; returns false otherwise
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(window_array[i].isOccupied())
      return false;
  }
  return true;
}

bool Registrar::freeWindows() //returns true if at least one window is empty
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(!window_array[i].isOccupied())
      return true;
  }
  return false;
}

bool Registrar::registrarFinished() //checks if all windows are empty and no more students are waiting in the queue
{
  if(!waiting_students->empty()) //if there are still students, automatically return false
  {
    return false;
  }
  else
  {
    for(int i = 0; i < window_array_size; ++i) //iterate through windows; if at least one is still occupied return false; else return true
    {
      if(window_array[i].isOccupied())
      {
        return false;
      }
    }
    return true;
  }
}

void Registrar::findNextFreeWindow(int time) //finds the next available window and assigns the next student in the queue, parameter used for data collection
{
  for(int i = 0; i < window_array_size; ++i) //iterates through the window array
  {
    if(!window_array[i].isOccupied()) //upon finding the first unoccupied window, assign a student from the queue
    {
      window_idles->addTime(window_array[i].getIdleTime()); //stores the window's idle time in the respective TimeCollector for data purposes
      student_waits->addTime(time - waiting_students->front().getArrivalTime()); //stores the student's wait time in the respective TimeCollector for data purposes
      window_array[i].assignStudent(waiting_students->dequeue()); //removes the student from the queue and assigns them to the window
      cout << "Window " << i + 1 << " has begun serving a student (" << window_array[i].getStudentTime() << " minutes needed)." << endl; //prints to console to inform user of what happened
      break;
    }
  }
}

void Registrar::addStudentToQueue(Student s) //adds a Student to the queue
{
  waiting_students->enqueue(s);
  cout << "A student (needs " << s.getTimeNeeded() << " minutes) has gotten in line. " << endl; //prints to console to inform user of what happened
}

void Registrar::registrarCycle() //simulates one iteration of time for the registrar
{
  for(int i = 0; i < window_array_size; ++i) //runs thru windowCycle for each Window
  {
    window_array[i].windowCycle();
  }
}

void Registrar::resizeWindowArray(int size) //resizes the window array
{
  delete[] window_array; //deletes the current window array
  window_array_size = size; //sets member variable to passed parameter
  window_array = new Window[size]; //allocates memory for a new array
}

void Registrar::printWindowIdleData() //prints the data collected regarding windows' idle time via TimeCollector
{
  cout << "WINDOW DATA: " << endl;
  cout << "Average Idle Time: " << window_idles->mean() << " minutes" << endl; //average
  cout << "Longest Idle Time: " << window_idles->max() << " minutes" << endl; //longest idle time
  cout << "Number of windows idle for over 5 minutes: " << window_idles->numberAbove(5) << endl; //number of windows idle for over 5 minutes (not including equal to 5)
  cout << endl;
}

void Registrar::printStudentWaitData() //prints the data collected regarding the students' wait times via TimeCollector
{
  cout << "STUDENT DATA: " << endl;
  cout << "Average Wait Time: " << student_waits->mean() << " minutes" << endl; //average
  cout << "Median Wait Time: " << student_waits->median() << " minutes" << endl; //median
  cout << "Longest Wait Time: " << student_waits->max() << " minutes" << endl; //longest wait time
  cout << "Number of students waiting for over 10 minutes: " << student_waits->numberAbove(10) << endl; //mnumber of wait times above 10 min (not including equal to 10)
  cout << endl;
}
