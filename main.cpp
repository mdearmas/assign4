#include "DoublyLinkedList.h"

int main(int argc, char** argv)
{
  DoublyLinkedList<int> c;
  c.insertFront(2);
  c.insertFront(3);
  c.insertFront(4);
  c.removeFront();
  c.insertBack(10);
  c.insertBack(7);
  c.removeBack();
  c.removePos(1);

  for(int i = 0; i < 2; ++i)
  {
    cout << c.begin() << endl;
    c.removeFront();
  }

  return 0;
}
