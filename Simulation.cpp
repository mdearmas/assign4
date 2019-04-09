#include "Simulation.h"

Simulation::Simulation()
{
  r = new Registrar();
  student_deck = new Student[50];
  index = 0;
  student_number = 0;
  array_size = 50;
}

Simulation::~Simulation()
{
  delete r;
  delete[] student_deck;
}

bool Simulation::fileread(string filename)
{
  ifstream input_file;

  bool first_line = true; //bool allows us to keep track of the first line, which contains the number of registrar windows
  bool expecting_time = false; //bool allows us to keep track of the clock tick when students arrive
  bool expecting_student_amount = false; //allows us to know if the next line will contain the number of students arriving at a certain time
  bool expecting_student_info = false; //allows us to know if the next lines are all student information

  int size;
  int arrival_time;
  int expected_students;
  int time_needed;
  int current_students = 0;

  string line;

  input_file.open(filename);

  if(input_file.is_open())
  {
    try
    {
      while( getline(input_file, line) )
      {
        if(first_line)
        {
          size = stoi(line);
          if(size < 1 || input_file.fail())
            throw BadFileException("Incorrect file format.");
          else
          {
            r->resizeWindowArray(size);
            first_line = false;
            expecting_time = true;
          }
        }
        else if(expecting_time)
        {
          arrival_time = stoi(line);
          if(arrival_time < 1 || input_file.fail())
            throw BadFileException("Incorrect file format.");
          else
          {
            expecting_time = false;
            expecting_student_amount = true;
          }
        }
        else if(expecting_student_amount)
        {
          expected_students = stoi(line);
          if(expected_students < 1 || input_file.fail())
            throw BadFileException("Incorrect file format.");
          else
          {
            expecting_student_amount = false;
          }
        }
        else
        {
          time_needed = stoi(line);

          if(time_needed < 1 || input_file.fail())
            throw BadFileException("Incorrect file format.");
          else
          {
            if(studentDeckFull())
              resizeStudentDeck();

            student_deck[index] = Student(arrival_time, time_needed);

            ++index;
            ++student_number;
            ++current_students;

            if(current_students == expected_students)
            {
              expecting_time = true;
            }
          }
        }
      }
      input_file.close();
      return true;
    }
    catch(BadFileException& e)
    {
      cout << e.getErrorMessage() << endl;
      return false;
    }
  }
  else
  {
    return false;
  }
}

void Simulation::resizeStudentDeck()
{
  array_size = array_size * 2; //doubles the size of the array
  Student* new_deck = new Student[array_size]; //allocates an array of the new doubled size

  for(int i = 0; i < student_number; ++i) //copies all elements of the existing array to the new array
  {
    new_deck[i] = student_deck[i];
  }

  delete[] student_deck; //deallocates the memory currently used by student_deck
  student_deck = new_deck; //assigns the location of new_deck to student_deck
}
