/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Simulation.h, contains the definition for the Simulation class, which controls user input and overarching simulation management.
  This also includes the class definition for a BadFileException, which is thrown if file input is incorrect.
*/
#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <fstream> //allows us access to file I/O

#include "Registrar.h"
#include "Student.h"

using namespace std;

class Simulation {
public:
  Simulation(); //default constructor
  ~Simulation(); //destructor

  bool fileread(string filename); //reads in a file and creates the necessary objects for the simulation to run
  bool simulationOver(); //checks all conditions that would instigate the end of the simulation

  void addTimeMatches(int t); //adds all Students for which arrival_time == t to the Registrar's waiting_students queue
  void moveStudents(int t); //simulates movement during a minute at the office
  void resizeStudentDeck(); //resizes student_deck array
  void printAnalytics(); //prints the results of the simulation

  bool noStudentsRemaining() { return (remaining_student_number <= 0); } //returns true if there are still students on deck to enter the registrar
  bool studentDeckFull() { return (total_student_number == array_size); } //returns true if the total number of students equals the max capacity of the array

private:
  Registrar* r; //the Registrar office space for the simulation
  Student* student_deck; //an array containing the list of students who will arrive over the course of the simulation (but have not yet arrived in the office space)

  int index; //the index of the student_deck to keep track of where the next student goes in the array
  int total_student_number; //the total number of students
  int remaining_student_number; //the number of students still waiting to enter the registrar
  int array_size; //the max size of the student_deck array
};

class BadFileException //class definition for an exception that is thrown if the file has incorrect format
{
public:
  BadFileException(string message) : error_message(message) { } //constructor with initializer list
  string getErrorMessage() { return error_message; } //accessor that returns the error message
private:
  string error_message; //the error message associated with the error object
};

#endif
