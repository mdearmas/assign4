#ifndef REGISTRAR_H_
#define REGISTRAR_H_

#include <iostream>

#include "GenQueue.h"
#include "Window.h"
#include "Student.h"

using namespace std;

class Registrar {
public:
  Registrar();
  Registrar(int w);
  ~Registrar();

  bool allWindowsEmpty();
  bool freeWindows();
  bool registrarFinished();

  Window* findNextFreeWindow();

  void addStudentToQueue(Student s);
  void registrarCycle();

  Window* window_array;
  int window_array_size;
  GenQueue<Student> *waiting_students;
};

#endif
