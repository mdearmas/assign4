#include "DoublyLinkedList.h"
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"

int main(int argc, char** argv)
{
  GenQueue<int> c;
  c.enqueue(2);
  c.enqueue(3);
  c.enqueue(4);
  c.dequeue();

  for(int i = 0; i < 2; ++i)
  {
    cout << c.dequeue() << endl;
  }

  Student s(1, 0, 2);
  Window w;
  w.assignStudent(s);

  for(int i = 1; i < 4; ++i)
  {
    w.windowCycle();
    if(w.occupied_time == s.time_needed)
    {
      w.removeStudent();
      break;
    }
  }

  return 0;
}
