/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, TimeCollector.h, contains the class definition for TimeCollector, which gathers integer times information
  an array in order to calculate statistics on them.
*/
#ifndef TIMECOLLECTOR_H_
#define TIMECOLLECTOR_H_

#include <iostream>

using namespace std;

class TimeCollector {
public:
  TimeCollector(); //constructor
  ~TimeCollector(); //destructor

  void addTime(int i); //adds a time entry into the array
  void swapSort(); //sorts the array from greatest to least
  void resize(); //resizes the array
  void printList(); //prints the list of times collected, used during testing

  double mean(); //calculates the mean
  double median(); //finds the median
  int max(); //returns the max value of the set
  int numberAbove(int k); //returns the total number of entries that are greater than the passed parameter

private:
  int *array; //the array that contains the time values
  int array_size; //the max size of the array
  int index; //the index where the next entry will be placed
};

#endif
