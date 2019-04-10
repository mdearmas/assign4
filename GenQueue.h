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
    try
    {
      if(empty())
        throw EmptyListException("ERROR: attempted to dequeue an empty queue");
      else
      {
        T temp = d->begin();
        d->removeFront();
        return temp;
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl;
    }

  }

  T front() { return d->begin(); }

  int size() { return d->getSize(); }

  bool empty() { return d->isEmpty(); }

  DoublyLinkedList<T> *d;
};
