#include "Assignment4.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv)
{
  string fileName;
  Simulation assignment;

  cout << "Please insert a file name:" << endl;
  cin >> fileName;

  assignment.Run(fileName);

  return 0;
}
