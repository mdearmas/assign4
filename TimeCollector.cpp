/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, TimeCollector.cpp, contains the out-of-class member functions for TimeCollector.
*/
#include "TimeCollector.h"

TimeCollector::TimeCollector() //constructor
{
  array = new int[16];
  array_size = 16;
  for(int i = 0; i < array_size; ++i)
  {
    array[i] = -1; //fills all space in the array with -1 to keep the unfilled entries from accidentally interfering with other functions like swapSort()
  }
  index = 0;
}

TimeCollector::~TimeCollector() //destructor
{
  delete[] array;
}

void TimeCollector::addTime(int t) //adds a time entry into the array
{
  array[index] = t;
  index++; //increments index to next empty spot
}

void TimeCollector::swapSort() //sorts the array from greatest to least
{
  bool swapped = true; //bool to mark if a swap happened
  int temp;
  while(swapped)
  {
    swapped = false; //if a swap doesn't happen in the following iteration, then the array is sorted
    for(int i = 0; i < index; ++i)
    {
      if(array[i] < array[i+1])
      {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        swapped = true;
      }
    }
  }
}

void TimeCollector::resize() //resizes the array
{
  int temp = array_size;
  array_size = array_size * 2; //doubles the size of the array
  int* new_array = new int[array_size]; //allocates an array of the new doubled size

  for(int i = 0; i < temp; ++i) //copies all elements of the existing array to the new array
  {
    new_array[i] = array[i];
  }

  delete[] array; //deallocates the memory currently used by student_deck
  array = new_array; //assigns the location of new_deck to student_deck
}

void TimeCollector::printList() //prints the list of times collected
{
  for(int i = 0; i < index; ++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

double TimeCollector::mean() //calculates mean
{
  double sum = 0;
  for(int i = 0; i < index; ++i)
  {
    sum += array[i];
  }
  return(sum / index);
}

double TimeCollector::median() //finds median
{
  swapSort(); //sorts the array in order
  if(index % 2 == 1) //if there are an odd number of entries, then the median is the middle element
    return(array[index / 2]);
  else //if there are an even number of entries, then the median is the two middle elements divided by 2
  {
    return ( (double) ( array[index / 2] + array[(index/2) - 1] ) / 2);
  }
}

int TimeCollector::max() //returns the max value of the set
{
  swapSort();
  return array[0]; //if the array is ordered from greatest to least, then array[0] is the greatest element
}

int TimeCollector::numberAbove(int k) //returns the total number of entries that are greater than the passed parameter
{
  int total = 0;
  for(int i = 0; i < index; ++i)
  {
    if(array[i] > k)
      total++;
  }
  return total;
}
