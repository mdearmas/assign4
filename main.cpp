#include "Student.h"
#include "Window.h"
#include "Registrar.h"
#include "Simulation.h"
#include "TimeCollector.h"

int main(int argc, char** argv)
{
  Simulation runner;
  string filename;
  int time = 1;

  cout << "Please enter the name of your file: ";
  cin >> filename;

  if(runner.fileread(filename))
  {
    while(true)
    {
      runner.addTimeMatches(time);
      runner.moveStudents();
      time++;
      cout << "..." << endl;
      if(runner.simulationOver()) //change to simulationOver()
        break;
    }
  }
  else
  {
    cout << "The file was not able to be opened. Exiting program." << endl;
  }

  return 0;
}
