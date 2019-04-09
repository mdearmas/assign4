#include "Student.h"
#include "Window.h"
#include "Registrar.h"

int main(int argc, char** argv)
{
  Registrar r(3);
  GenQueue<Student> *s = r.waiting_students;
  Window *w = r.window_array;

  for(int i = 0; i < 3; ++i)
  {
    Student s(1, 0, i+1);
    r.addStudentToQueue(s);
  }

  while(r.freeWindows())
  {
    Window *w = r.findNextFreeWindow();
    w->assignStudent(s->dequeue());
  }

  while(!r.registrarFinished())
  {
    r.registrarCycle();
  }

  return 0;
}
