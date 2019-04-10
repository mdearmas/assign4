#ifndef REGISTRAR_H_
#define REGISTRAR_H_

#include <iostream>

#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
#include "TimeCollector.h"

using namespace std;

class Registrar {
public:
  Registrar();
  Registrar(int w);
  ~Registrar();

  bool allWindowsEmpty();
  bool freeWindows();
  bool registrarFinished();

  void findNextFreeWindow(int time);
  void addStudentToQueue(Student s);
  void registrarCycle();
  void resizeWindowArray(int size);
  void printTimeCollectors();

  GenQueue<Student>* getStudentQueue() { return waiting_students; }
  bool studentQueueEmpty() { return (waiting_students->empty()); }

private:
  Window* window_array;
  int window_array_size;
  GenQueue<Student> *waiting_students;

  TimeCollector* window_idles;
  TimeCollector* student_waits;
};

#endif
