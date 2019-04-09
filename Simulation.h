#ifndef SIMULATION_H_
#define SIMULATION_H_

class Simulation {
public:
  Simulation();
  ~Simulation();

  void fileread(string filename);
  void addTimeMatches(int t); //adds all Students for which arrival_time == t to the Registrar's waiting_students queue
  void moveStudents(); //if there are free windows in the registar and students waiting, free windows are filled with students. then registrarCycle is called.
  void resize(); //resizes student_deck array

  bool noStudentsRemaining() { return (student_number <= 0); } //bool, returns true if there are still students on deck to enter the registrar
  bool studentDeckFull() { return (student_number == array_size); }
  bool simulationOver() { return (r.registrarFinished() && noStudentsRemaining()); }

private:
  Registrar* r;
  Student* student_deck;
  int index;
  int student_number;
  int array_size;
};

#endif
