/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Registrar.h, contains the class definition for what will serve as the base for the simulation.
  It contains both a queue of Students and an array of Windows to simulate the office environment. It also contains
  TimeCollector objects to store results from the simulation.
*/
#ifndef REGISTRAR_H_
#define REGISTRAR_H_

#include <iostream>

#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
#include "TimeCollector.h"

using namespace std;

class Registrar {
public:
  Registrar(); //default constructor
  Registrar(int w); //overloaded constructor
  ~Registrar(); //destructor

  bool allWindowsEmpty(); //returns true if all windows in the array are not occupied
  bool freeWindows(); //returns true if at least one window is not occupied
  bool registrarFinished(); //checks if all windows are empty and no students are currently in the queue

  void findNextFreeWindow(int time); //finds the next available window and assigns the next student in the queue, parameter used for data collection
  void addStudentToQueue(Student s); //adds a Student to the queue
  void registrarCycle(); //simulates the passing of one minute in the registrar (applies windowCycle to all windows)
  void resizeWindowArray(int size); //resizes the window array
  void printWindowIdleData(); //prints the data collected regarding windows' idle time via TimeCollector
  void printStudentWaitData(); //prints the data collected regarding the students' wait times via TimeCollector

  GenQueue<Student>* getStudentQueue() { return waiting_students; } //accessor for the queue, used during testing
  bool studentQueueEmpty() { return (waiting_students->empty()); } //returns true if queue is empty, used during testing

private:
  Window* window_array; //the collection of windows in the registrar
  int window_array_size; //the number of windows
  GenQueue<Student> *waiting_students; //the student queue

  TimeCollector* window_idles; //TimeCollector object to store info about the windows' idle times
  TimeCollector* student_waits; //TimeCollector object to store info about the students' wait times
};

#endif
