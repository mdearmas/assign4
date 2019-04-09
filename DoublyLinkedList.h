#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "GenList.h"

template <typename T>
class ListNode {
public:
  ListNode()
  {
    next = NULL;
    prev = NULL;
  }

  ListNode(T obj)
  {
    data = obj;
    next = NULL;
    prev = NULL;
  }

  ~ListNode() //since nothing has been allocated with new, the destructor just ensures that the node's pointers are nulled out before proceeding
  {
    next = NULL;
    prev = NULL;
  }

  T data;
  ListNode<T>* next;
  ListNode<T>* prev;
};


template <typename T>
class DoublyLinkedList : public GenList<T> {
public:
  ListNode<T> *front;
  ListNode<T> *back;
  int size;

  DoublyLinkedList()
  {
    front = NULL;
    back = NULL;
    size = 0;
  }

  virtual ~DoublyLinkedList()
  {
    while(size > 0)
    {
      ListNode<T> *curr = front;
      if(size > 1)
      {
        front = front->next;
        front->prev = NULL;
        curr->next = NULL;
      }
      size--;
      delete curr;
    }
  }

  void insertFront(T obj)
  {
    ListNode<T> *node = new ListNode<T>(obj);

    if(size == 0)
    {
      back = node;
    }
    else
    {
      node->next = front;
      front->prev = node;
    }

    front = node;
    size++;
  }

  virtual void insertBack(T obj)
  {
    ListNode<T> *node = new ListNode<T>(obj);

    if(size == 0)
    {
      front = node;
    }
    else
    {
      node->prev = back;
      back->next = node;
    }

    back = node;
    size++;
  }

  virtual void insertPos(int k, T obj)
  {
    int key = 0;
    ListNode<T>* curr = front;
    while(key != k)
    {
      curr = curr->next;
      ++key;
      if(curr == NULL)
        break;
    }

    if(curr != NULL)
    {
      if(curr == front)
        insertFront(obj);
      else if(curr == back)
        insertBack(obj);
      else
      {
        ListNode<T> *node = new ListNode<T>(obj);
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
        size++;
      }
    }
  }

  virtual void removeFront()
  {
    if(!isEmpty())
    {
      ListNode<T> *curr = front;
      if(size > 1)
      {
        front = front->next;
        front->prev = NULL;
        curr->next = NULL;
      }
      size--;
      delete curr;
    }
  }

  virtual void removeBack()
  {
    if(!isEmpty())
    {
      ListNode<T> *curr = back;
      if(size > 1)
      {
        back = back->prev;
        back->next = NULL;
        curr->prev = NULL;
      }
      size--;
      delete curr;
    }
  }

  virtual void removePos(int k)
  {
    if(!isEmpty())
    {
      int key = 0;
      ListNode<T> *curr = front;
      while(key != k)
      {
        curr = curr->next;
        ++key;
        if(curr == NULL)
          break;
      }

      if(curr != NULL)
      {
        if(curr == front)
          front == curr->next;
        else
        {
          curr->prev->next = curr->next;
        }

        if(curr == back)
          back == curr->prev;
        else
        {
          curr->next->prev = curr->prev;
        }

        curr->next = NULL;
        curr->prev = NULL;
        size--;
        delete curr;
      }
    }
  }

  virtual bool isEmpty() { return (size <= 0); }

  virtual T begin() { return front->data; }
  virtual T end() { return back->data; }
  int getSize() { return size; }
};

#endif
