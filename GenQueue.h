/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, GenQueue.h, contains the template for a queue abstract data type derived from a doubly linked list.
*/
#include "DoublyLinkedList.h"

template <typename T>
class GenQueue {
public:
  GenQueue() //default constructor
  {
    d = new DoublyLinkedList<T>();
  }

  ~GenQueue() //destructor
  {
    delete d;
  }

  void enqueue(T obj) //adds object to back of queue
  {
    d->insertBack(obj);
  }

  T dequeue() //removes object from front of queue
  {
    try
    {
      if(empty()) //throws an exception if queue is empty
        throw EmptyListException("ERROR: attempted to dequeue an empty queue");
      else
      {
        T temp = d->begin(); //stores the data before the node is removed
        d->removeFront(); //uses the doubly linked list removeFront method
        return temp; //returns the stored data
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //print error message to console
    }

  }

  T front() { return d->begin(); } //returns the data stored at the front of the queue

  int size() { return d->getSize(); } //returns the size of the queue

  bool empty() { return d->isEmpty(); } //returns true if the queue is empty

  DoublyLinkedList<T> *d; //the doubly linked list that forms the base of the queue
};
