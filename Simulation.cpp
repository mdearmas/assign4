/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, Simulation.cpp, contains the out-of-class member functions for Simulation.
*/
#include "Simulation.h"

Simulation::Simulation() //constructor
{
  r = new Registrar(); //creates a default registrar object (we use resize later to alter the size)
  student_deck = new Student[50]; //allocates an array of Students

  index = 0;
  total_student_number = 0;
  remaining_student_number = 0;
  array_size = 50;
}

Simulation::~Simulation() //destructor
{
  delete r;
  delete[] student_deck; //deallocates array
}

bool Simulation::fileread(string filename) //reads in a file and creates the necessary objects for the simulation to run
{
  ifstream input_file;

  bool first_line = true; //bool allows us to keep track of the first line, which contains the number of registrar windows
  bool expecting_time = false; //bool allows us to keep track of the clock tick when students arrive
  bool expecting_student_amount = false; //allows us to know if the next line will contain the number of students arriving at a certain time
  bool expecting_student_info = false; //allows us to know if the next lines are all student information

  int size; //number of windows
  int arrival_time; //the minute the students will arrive
  int expected_students; //the number of students that will arrive at a set minute
  int time_needed; //the amount of time each student will need at a window
  int current_students = 0; //the number of students currently stored in the array for that arrival minute

  string line;

  input_file.open(filename);

  if(input_file.is_open()) //checks to see if the file was successfully opened
  {
    try
    {
      while( getline(input_file, line) ) //while there is content in the file
      {
        if(first_line) //only the first line of the file contains the number of windows
        {
          size = stoi(line);
          if(size < 1 || input_file.fail()) //if the size is less than 1 and/or the input somehow failed, throw exception
            throw BadFileException("ERROR: incorrect file format");
          else
          {
            r->resizeWindowArray(size); //resize array accordingly
            cout << "Registrar has " << size << " windows open." << endl; //prints to console to inform user of what happened
            first_line = false; //sets first line to false
            expecting_time = true; //next, we're expecting an arrival time
          }
        }
        else if(expecting_time) //enters block only if expecting an arrival time
        {
          arrival_time = stoi(line);
          if(arrival_time < 1 || input_file.fail()) //if the time is less than one and/or the input somehow failed, throw exception
            throw BadFileException("ERROR: incorrect file format");
          else
          {
            expecting_time = false; //now no longer expecting time
            expecting_student_amount = true; //the next line will contain the number of students arriving at that time
          }
        }
        else if(expecting_student_amount) //enters only if we're expecting the next line to give us the number of students arriving at a certain time
        {
          expected_students = stoi(line);
          if(expected_students < 1 || input_file.fail()) //if the amount is less than 1 and/or the input failed, throw exception
            throw BadFileException("ERROR: incorrect file format");
          else
          {
            expecting_student_amount = false; //now we're no longer expecting a number of students
          }
        }
        else //if everything else was false, that means we're now reading lines that contain individual students' times needed at windows
        {
          time_needed = stoi(line);

          if(time_needed < 1 || input_file.fail()) //if the time is less than 1 and/or the input failed, throw exception
            throw BadFileException("ERROR: incorrect file format");
          else
          {
            if(studentDeckFull()) //if the student deck if full, resize it
              resizeStudentDeck();

            student_deck[index] = Student(arrival_time, time_needed); //set the next space in the array to a new student object

            ++index; //increment index
            ++total_student_number; //increment total number of students
            ++current_students; //increment the number of students we've received for that arrival minute

            if(current_students == expected_students) //if the number of students we've received equals the number we're expecting for the arrival time, reset the bools
            {
              expecting_time = true; //next line will contain the next arrival time
              current_students = 0; //clears out variable
            }
          }
        }
      }
      remaining_student_number = total_student_number; //sets the remaining_student_number variable equal to the total number of students
      input_file.close(); //close file
      return true; //returns true because the fileread was successful
    }
    catch(BadFileException& e)
    {
      cout << e.getErrorMessage() << endl; //prints error message to console
      return false; //returns false since attempt failed
    }
    catch(const invalid_argument& ia) //Source: http://www.cplusplus.com/reference/stdexcept/invalid_argument/
    {
      cout << "ERROR: incorrect file format" << endl; //prints error to console
      return false; //returns false since attempt failed
    }
  }
  else
  {
    return false; //returns false since attempt to open file failed
  }
}

bool Simulation::simulationOver()
{
  if(r->registrarFinished() && remaining_student_number<=0)
    return true;
  else
    return false;
}

void Simulation::addTimeMatches(int t)
{
  for(int i = (total_student_number - remaining_student_number); i < total_student_number; ++i)
  {
    if(t == student_deck[i].getArrivalTime())
    {
      r->addStudentToQueue(student_deck[i]);
      remaining_student_number--;
    }
  }
}

void Simulation::moveStudents(int t)
{
  while(!r->studentQueueEmpty() && r->freeWindows())
  {
    r->findNextFreeWindow(t);
  }
  r->registrarCycle();
}

void Simulation::resizeStudentDeck()
{
  array_size = array_size * 2; //doubles the size of the array
  Student* new_deck = new Student[array_size]; //allocates an array of the new doubled size

  for(int i = 0; i < total_student_number; ++i) //copies all elements of the existing array to the new array
  {
    new_deck[i] = student_deck[i];
  }

  delete[] student_deck; //deallocates the memory currently used by student_deck
  student_deck = new_deck; //assigns the location of new_deck to student_deck
}

void Simulation::printAnalytics()
{
  r->printStudentWaitData();
  r->printWindowIdleData();
}
