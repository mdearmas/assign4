#ifndef GENLIST_H_
#define GENLIST_H_

#include <iostream>

using namespace std;

template <typename T>
class GenList {
public:
  virtual void insertFront(T obj) = 0;
  virtual void insertBack(T obj) = 0;
  virtual void insertPos(int k, T obj) = 0;

  virtual void removeFront() = 0;
  virtual void removeBack() = 0;
  virtual void removePos(int k) = 0;

  virtual bool isEmpty() = 0;

  virtual T begin() = 0;
  virtual T end() = 0;
};

#endif
