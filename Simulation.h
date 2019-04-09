#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <fstream>

#include "Registrar.h"
#include "Student.h"

using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();

  bool fileread(string filename);

  void addTimeMatches(int t); //adds all Students for which arrival_time == t to the Registrar's waiting_students queue
  void moveStudents(); //if there are free windows in the registar and students waiting, free windows are filled with students. then registrarCycle is called.
  void resizeStudentDeck(); //resizes student_deck array

  bool simulationOver();
  bool noStudentsRemaining() { return (remaining_student_number <= 0); } //bool, returns true if there are still students on deck to enter the registrar
  bool studentDeckFull() { return (total_student_number == array_size); }

private:
  Registrar* r;
  Student* student_deck;
  int index;
  int total_student_number;
  int remaining_student_number;
  int array_size;
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
