#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

class TimeCollector {
public:
  TimeCollector();
  ~TimeCollector();

  void addTime(int i);
  int mean();
  int median();
  int max();
  int numberAbove(int i);

private:
  DoublyLinkedList<int> d;
}
