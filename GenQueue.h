#include "DoublyLinkedList.h"

template <typename T>
class GenQueue {
public:
  GenQueue()
  {
    d = new DoublyLinkedList<T>();
  }

  ~GenQueue()
  {
    delete d;
  }

  void enqueue(T obj)
  {
    d->insertBack(obj);
  }

  T dequeue()
  {
    if(empty())
    {
      cout << "ERROR: Attempted to dequeue an empty queue." << endl;
    }
    else
    {
      T temp = d->begin();
      d->removeFront();
      return temp;
    }
  }

  T front() { return d->begin(); }

  int size() { return d->getSize(); }

  bool empty() { return d->isEmpty(); }

  DoublyLinkedList<T> *d;
};
