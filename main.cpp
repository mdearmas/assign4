#include "Student.h"
#include "Window.h"
#include "Registrar.h"

int main(int argc, char** argv)
{
  Registrar r(3);
  GenQueue<Student> *s = r.waiting_students;
  Student test[5];
  int test_size = 5;
  int time = 1;

  test[0] = Student(1, 5);
  test[1] = Student(2, 3);
  test[2] = Student(2, 1);
  test[3] = Student(3, 2);
  test[4] = Student(4, 4);

  while(true)
  {
    for(int i = 0; i < 5; ++i)
    {
      if(time == test[i].arrival_time)
      {
        r.addStudentToQueue(test[i]);
        test_size--;
      }
    }
    while(!s->empty() && r.freeWindows())
    {
      r.findNextFreeWindow();
    }
    r.registrarCycle();
    time++;
    cout << "..." << endl;
    if(r.registrarFinished() && test_size==0)
      break;
  }

  return 0;
}
