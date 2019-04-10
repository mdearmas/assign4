#include "TimeCollector.h"

TimeCollector::TimeCollector()
{
  array = new int[16];
  array_size = 16;
  for(int i = 0; i < array_size; ++i)
  {
    array[i] = -1;
  }
  index = 0;
}

TimeCollector::~TimeCollector()
{
  delete[] array;
}

void TimeCollector::addTime(int t)
{
  array[index] = t;
  index++;
}

void TimeCollector::swapSort()
{
  bool swapped = true; //bool to mark if a swap happened
  int temp;
  while(swapped)
  {
    swapped = false;
    for(int i = 0; i < index; ++i)
    {
      if(array[i] < array[i+1])
      {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        swapped = true;
      }
    }
  }
}

/*void TimeCollector::printList()
{
  for(int i = 0; i < index; ++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}*/

void TimeCollector::resize()
{
  int temp = array_size;
  array_size = array_size * 2; //doubles the size of the array
  int* new_array = new int[array_size]; //allocates an array of the new doubled size

  for(int i = 0; i < temp; ++i) //copies all elements of the existing array to the new array
  {
    new_array[i] = array[i];
  }

  delete[] array; //deallocates the memory currently used by student_deck
  array = new_array; //assigns the location of new_deck to student_deck
}

double TimeCollector::mean()
{
  double sum = 0;
  for(int i = 0; i < index; ++i)
  {
    sum += array[i];
  }
  return(sum / index);
}

int TimeCollector::median()
{
  swapSort();
  if(index % 2 == 1)
    return(array[index / 2]);
  else
  {
    return(( array[index / 2] + array[(index/2) - 1] ) / 2);
  }
}

int TimeCollector::max()
{
  swapSort();
  return array[0];
}

int TimeCollector::numberAbove(int k)
{
  int total = 0;
  for(int i = 0; i < index; ++i)
  {
    if(array[i] > k)
      total++;
  }
  return total;
}
