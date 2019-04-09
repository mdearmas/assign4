#include "Student.h"
#include "Window.h"
#include "Registrar.h"

int main(int argc, char** argv)
{
  Registrar r(3);
  GenQueue<Student> *s = r.waiting_students;

  for(int i = 5; i > 0; --i)
  {
    Student s(1, 0, i);
    r.addStudentToQueue(s);
  }

  while(true)
  {
    while(!s->empty() && r.freeWindows())
    {
      r.findNextFreeWindow();
    }
    r.registrarCycle();
    cout << "..." << endl;
    if(r.registrarFinished())
      break;
  }

  return 0;
}
