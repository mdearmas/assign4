#ifndef TIMECOLLECTOR_H_
#define TIMECOLLECTOR_H_

#include <iostream>

using namespace std;

class TimeCollector {
public:
  TimeCollector();
  ~TimeCollector();

  void addTime(int i);
  void swapSort();
  void printList();
  void resize();

  int mean();
  int median();
  int max();
  int numberAbove(int i);

private:
  int *array;
  int array_size;
  int index;
};

#endif
