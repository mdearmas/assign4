#include "DoublyLinkedList.h"
#include "GenQueue.h"

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

  return 0;
}
