#include "Registrar.h"

Registrar::Registrar()
{
  window_array = new Window[10];
  window_array_size = 10;
  waiting_students = new GenQueue<Student>();
}

Registrar::Registrar(int w)
{
  window_array = new Window[w];
  window_array_size = w;
  waiting_students = new GenQueue<Student>();
}

Registrar::~Registrar()
{
  delete[] window_array;
  delete waiting_students;
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

Window* Registrar::findNextFreeWindow()
{
  for(int i = 0; i < window_array_size; ++i)
  {
    if(!window_array[i].isOccupied())
      return &window_array[i];
  }
  return NULL;
}

void Registrar::addStudentToQueue(Student s)
{
  waiting_students->enqueue(s);
  cout << "Student with " << s.time_needed << " minutes needed added to queue. " << endl;
}

void Registrar::registrarCycle()
{
  for(int i = 0; i < window_array_size; ++i)
  {
    window_array[i].windowCycle();
  }

  ListNode<Student> *curr = waiting_students->d->front;
  while(curr != NULL)
  {
    curr->data.studentCycle();
    curr = curr->next;
  }
}
