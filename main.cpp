/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, main.cpp, runs the actual Registrar Simulation. It allows the user to input a filename and then,
  via the Simulation object, reports to the console the events of the simulation before finally outputting the statistics
  of the simulation.
*/
#include "Simulation.h"

int main(int argc, char** argv)
{
  Simulation runner;
  string filename;
  int time = 0;

  cout << "Please enter the name of your file: ";
  cin >> filename;

  if(runner.fileread(filename)) //if the file is not opened successfully, then the simulation will not run
  {
    while(true)
    {
      runner.addTimeMatches(time); //adds all students whose arrival time matches the current time to the queue
      runner.moveStudents(time); //simulates the movement during a single minute at the office
      time++;
      if(runner.simulationOver()) //if the simulation's end conditions have been met, break the loop
        break;
    }
    cout << "All students have been served, and the simulation has finished. Here are the results. " << endl;
    cout << endl;
    runner.printAnalytics(); //prints the results
  }
  else //in the event the file is not able to be opened
  {
    cout << "The file was not able to be opened. Exiting program." << endl;
  }

  return 0;
}
