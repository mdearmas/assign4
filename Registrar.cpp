#include "Registrar.h"

Registrar::Registrar()
{
  window_array = new Window[5];
  window_array_size = 5;
  waiting_students = new GenQueue<Student>();

  window_idles = new TimeCollector();
  student_waits = new TimeCollector();
}

Registrar::Registrar(int w)
{
  window_array = new Window[w];
  window_array_size = w;
  waiting_students = new GenQueue<Student>();

  window_idles = new TimeCollector();
  student_waits = new TimeCollector();
}

Registrar::~Registrar()
{
  delete[] window_array;
  delete waiting_students;
  delete window_idles;
  delete student_waits;
}

bool Registrar::allWindowsEmpty()
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(window_array[i].isOccupied())
      return false;
  }
  return true;
}

bool Registrar::freeWindows()
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(!window_array[i].isOccupied())
      return true;
  }
  return false;
}

bool Registrar::registrarFinished()
{
  if(!waiting_students->empty())
  {
    return false;
  }
  else
  {
    for(int i = 0; i < window_array_size; ++i)
    {
      if(window_array[i].isOccupied())
      {
        return false;
      }
    }
    return true;
  }
}

void Registrar::findNextFreeWindow(int time)
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(!window_array[i].isOccupied())
    {
      window_idles->addTime(window_array[i].getIdleTime());
      student_waits->addTime(time - waiting_students->front().getArrivalTime());
      window_array[i].assignStudent(waiting_students->dequeue());
      break;
    }
  }
}

void Registrar::addStudentToQueue(Student s)
{
  waiting_students->enqueue(s);
  cout << "Student with " << s.getTimeNeeded() << " minutes needed added to queue. " << endl;
}

void Registrar::registrarCycle()
{
  for(int i = 0; i < window_array_size; ++i)
  {
    window_array[i].windowCycle();
  }
}

void Registrar::resizeWindowArray(int size)
{
  delete[] window_array;
  window_array_size = size;
  window_array = new Window[size];
}

void Registrar::printTimeCollectors()
{
  cout << "Window Idles: " << endl;
  window_idles->printList();
  cout << "Student Waits: " << endl;
  student_waits->printList();
}
