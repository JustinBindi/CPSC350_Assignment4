#include "Assignment4.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
GenQueue<T>::GenQueue()
{
  myQueue = new T[256];
  mSize = 256;
  head = 0;
  tail = -1;
  numElements = 0;
}

template <class T>
GenQueue<T>::GenQueue(int maxSize)
{
  myQueue = new T[maxSize];
  mSize = maxSize;
  head = 0;
  tail = -1;
  numElements = 0;
}

template <class T>
void GenQueue<T>::insert(T d)
{
  if (!isFull())
  {
    if(tail == mSize-1)
    {
      tail = -1;
    }

    myQueue[++tail] = d;
    numElements++;
  }
}

template <class T>
T GenQueue<T>::remove()
{
  if (!isEmpty())
  {
    T c;
    c = myQueue[head];

    if(head == mSize)
    {
      head = 0;
    }

    head++;
    numElements--;

    return c;
  }
  else
  {
    throw "Stack is Empty EXCEPTION!";
  }
}

template <class T>
T GenQueue<T>::front()
{
  return myQueue[head];
}

template <class T>
bool GenQueue<T>::isFull()
{
  return (numElements == mSize);
}

template <class T>
bool GenQueue<T>::isEmpty()
{
  return (numElements == 0);
}

template <class T>
int GenQueue<T>::getSize()
{
  return numElements;
}

/////////////////////////////////////////////////////////////////////
Student::Student()
{
  this->waitTime = 0;
  this->neededWTime = 0;
  this->atWindow = false;
  this->studentID = 0;
  this->arrivalTime = 0;
  this->timeAtWindow = 0;
  this->studentDone = false;
}

Student::Student(int studentID)
{
  this->waitTime = 0;
  this->neededWTime = 0;
  this->atWindow = false;
  this->studentID = studentID;
  this->arrivalTime = 0;
  this->timeAtWindow = 0;
  this->studentDone = false;
}

//student setters
void Student::setStudentID(int studentID)
{
  this->studentID = studentID;
}
void Student::setStudentWindowTime(int neededWTime)
{
  this->neededWTime = neededWTime;
}
void Student::setStudentArrTime(int arrivalTime)
{
  this->arrivalTime = arrivalTime;
}
void Student::setStudentWaitTime(int waitTime)
{
  this->waitTime = waitTime+1;
}
void Student::setStudentatWindow(bool atWindow)
{
  this->atWindow = atWindow;
}
void Student::setStudentTimeAtWindow(int timeAtWindow)
{
  this->timeAtWindow = timeAtWindow+1;
}
void Student::setStudentDone(bool studentDone)
{
  this->studentDone = studentDone;
}

//student getters
int Student::getStudentID()
{
  return studentID;
}
int Student::getStudentWindowTime()
{
  return neededWTime;
}
int Student::getStudentArrTime()
{
  return arrivalTime;
}
int Student::getStudentWaitTime()
{
  return waitTime;
}
bool Student::getStudentatWindow()
{
  return atWindow;
}
int Student::getStudentTimeAtWindow()
{
  return timeAtWindow;
}
bool Student::getStudentDone()
{
  return studentDone;
}

//print student info
void Student::printSInfo()//(Student student)
{
  cout << "ID: " << studentID << endl;
  cout << "Needed Time: " << neededWTime << endl;
  cout << "Arrival Time: " << arrivalTime << endl;
  cout << "Wait Time: " << waitTime << endl;
  cout << "At Window?: " << atWindow << endl;
  cout << "Done?" << studentDone << endl;
  cout << "" << endl;
}

/////////////////////////////////////////////////////////////////////
Window::Window()
{
  this->idleTime = 0;
  this->studentHere = false;
  this->open = false;
  this->whichStudent = 0;
}

Window::Window(int idleTime)
{
  this->idleTime = idleTime;
  this->studentHere = false;
  this->open = false;
  this->whichStudent = 0;
}

//window setters
void Window::setWindowIdleTime(int idleTime)
{
  this->idleTime = idleTime+1;
}
void Window::setWindowStudentHere(bool studentHere)
{
  this->studentHere = studentHere;
}
void Window::setWindowOpen(bool open)
{
  this->open = open;
}
void Window::setWindowWhichStudentHere(int whichStudent)
{
  this->whichStudent = whichStudent;
}

//window getters
int Window::getWindowIdleTime()
{
  return idleTime;
}
bool Window::getWindowStudentHere()
{
  return studentHere;
}
bool Window::getWindowOpen()
{
  return open;
}
int Window::getWindowWhichStudentHere()
{
  return whichStudent;
}

//print window info
void Window::printWInfo()//(Window window)
{
  cout << "Idle Time: " << idleTime << endl;
  cout << "Student Here?: " << studentHere << endl;
  cout << "Which Student Here?: " << whichStudent << endl;
  cout << "Open?: " << open << endl;
  cout << "" << endl;

}

/////////////////////////////////////////////////////////////////////
Simulation::Simulation()
{
  loop = true;
  clock = 0;
  studentCounter = 0;
  doneCounter = 0;
  waitMean = 0;
  idleMean = 0;
  median = 0;
  longestSWaitTime = 0;
  longestWIdleTime = 0;
  numberWaitOver10 = 0;
  numberWaitOver5 = 0;
  meanSCounter = 0;
  meanWCounter = 0;
}

Simulation::Simulation(bool loopCondition)
{
  loop = loopCondition;
  clock = 0;
  studentCounter = 0;
  doneCounter = 0;
  waitMean = 0;
  idleMean = 0;
  median = 0;
  longestSWaitTime = 0;
  longestWIdleTime = 0;
  numberWaitOver10 = 0;
  numberWaitOver5 = 0;
  meanSCounter = 0;
  meanWCounter = 0;
}

void Simulation::Run(string fileName)
{
  //create group of default students with IDs
  Student s1(1);
  Student s2(2);
  Student s3(3);
  Student s4(4);
  Student s5(5);
  Student s6(6);
  Student s7(7);
  Student s8(8);
  Student s9(9);
  Student s10(10);
  Student s11(11);
  Student s12(12);
  Student s13(13);
  Student s14(14);
  Student s15(15);
  Student s16(16);
  Student s17(17);
  Student s18(18);
  Student s19(19);
  Student s20(20);

  //add students to student vector
  studentVector.push_back(s1);
  studentVector.push_back(s2);
  studentVector.push_back(s3);
  studentVector.push_back(s4);
  studentVector.push_back(s5);
  studentVector.push_back(s6);
  studentVector.push_back(s7);
  studentVector.push_back(s8);
  studentVector.push_back(s9);
  studentVector.push_back(s10);
  studentVector.push_back(s11);
  studentVector.push_back(s12);
  studentVector.push_back(s13);
  studentVector.push_back(s14);
  studentVector.push_back(s15);
  studentVector.push_back(s16);
  studentVector.push_back(s17);
  studentVector.push_back(s18);
  studentVector.push_back(s19);
  studentVector.push_back(s20);

  //create group of deault windows
  Window w1(0);
  Window w2(0);
  Window w3(0);
  Window w4(0);
  Window w5(0);
  Window w6(0);
  Window w7(0);
  Window w8(0);
  Window w9(0);
  Window w10(0);
  Window w11(0);
  Window w12(0);
  Window w13(0);
  Window w14(0);
  Window w15(0);
  Window w16(0);
  Window w17(0);
  Window w18(0);
  Window w19(0);
  Window w20(0);

  //add windows to window vector
  windowVector.push_back(w1);
  windowVector.push_back(w2);
  windowVector.push_back(w3);
  windowVector.push_back(w4);
  windowVector.push_back(w5);
  windowVector.push_back(w6);
  windowVector.push_back(w7);
  windowVector.push_back(w8);
  windowVector.push_back(w9);
  windowVector.push_back(w10);
  windowVector.push_back(w11);
  windowVector.push_back(w12);
  windowVector.push_back(w13);
  windowVector.push_back(w14);
  windowVector.push_back(w15);
  windowVector.push_back(w16);
  windowVector.push_back(w17);
  windowVector.push_back(w18);
  windowVector.push_back(w19);
  windowVector.push_back(w20);

  //read info from file and assign values to student objects
  ifstream myFile (fileName);
  while(getline(myFile, line))
  {
    fileRead.push_back(stoi(line));
  }
  for (int i = 0; i < fileRead[0]; i++)
  {
    windowVector[i].setWindowOpen(true);
  }
  fileRead.erase (fileRead.begin());
  while (fileRead.size() != 0)
  {
    deleter = 0;
    for (int i = 0; i < fileRead[1]; i++)
    {
      studentCounter++;
      studentVector[studentCounter-1].setStudentArrTime(fileRead[0]);
      studentVector[studentCounter-1].setStudentWindowTime(fileRead[i+2]);
    }
    deleter = 2 + fileRead[1];
    fileRead.erase (fileRead.begin(), fileRead.begin()+deleter);
  }

  GenQueue<Student> queue(20);

  while (loop)
  {
    clock++;
    doneCounter = 0;

    for (int i = 0; i < studentVector.size(); i++)
    {
      //increment student's time at window counter
      if (studentVector[i].getStudentatWindow() == true)
      {
        studentVector[i].setStudentTimeAtWindow(studentVector[i].getStudentTimeAtWindow());
      }

      //if clock matches a students arrival time, put them in queue
      if (clock == studentVector[i].getStudentArrTime())
      {
        queue.insert(studentVector[i]);
      }

      //if student has spent needed time at window
      if (studentVector[i].getStudentTimeAtWindow() >= studentVector[i].getStudentWindowTime() && studentVector[i].getStudentWindowTime() != 0)
      {
        studentVector[i].setStudentatWindow(false);
        studentVector[i].setStudentDone(true);
        doneCounter++;
        for (int i = 0; i < windowVector.size(); i++)
        {
          if (windowVector[i].getWindowWhichStudentHere() == studentVector[i].getStudentID())
          {
            windowVector[i].setWindowStudentHere(false);
          }
        }
      }
    }

      //if students are in queue, check if any windows are available and put them there if so.
      for (int i = 0; i < windowVector.size(); i++)
      {
        if (windowVector[i].getWindowOpen() == true && windowVector[i].getWindowStudentHere() == false)
        {
          if (!queue.isEmpty())
          {
            Student removeStudent = queue.remove();
            studentVector[removeStudent.getStudentID()-1].setStudentatWindow(true);
            windowVector[i].setWindowStudentHere(true);
            windowVector[i].setWindowWhichStudentHere(removeStudent.getStudentID());
          }
        }
      }

      //increment wait and idle times for students and windows
      for (int i = 0; i < windowVector.size(); i++)
      {
        if (windowVector[i].getWindowOpen() == true && windowVector[i].getWindowStudentHere() == false)
        {
          windowVector[i].setWindowIdleTime(windowVector[i].getWindowIdleTime());
        }
      }
      for (int i = 0; i < studentVector.size(); i++)
      {
        if (clock >= studentVector[i].getStudentArrTime() && studentVector[i].getStudentatWindow() == false &&
               studentVector[i].getStudentArrTime() != 0 && studentVector[i].getStudentDone() == false)
        {
          studentVector[i].setStudentWaitTime(studentVector[i].getStudentWaitTime());
        }
      }

      //break out of loop condition
      if (doneCounter == studentCounter)
      {
        loop = false;
      }
  }

    //find means
    for (int i = 0; i < studentVector.size(); i++)
    {
      if (studentVector[i].getStudentDone() == true)
      {
        waitMean += studentVector[i].getStudentWaitTime();
        waitTimesVector.push_back(studentVector[i].getStudentWaitTime());
        doneStudents.push_back(studentVector[i]);
        meanSCounter++;
      }

      if (studentVector[i].getStudentWaitTime() > 10)
      {
        numberWaitOver10++;
      }
    }
    for (int i = 0; i < windowVector.size(); i++)
    {
      if (windowVector[i].getWindowOpen() == true)
      {
        idleMean += windowVector[i].getWindowIdleTime();
        idleTimesVector.push_back(windowVector[i].getWindowIdleTime());
        meanWCounter++;
      }
      if (windowVector[i].getWindowIdleTime() > 5)
      {
        numberWaitOver5++;
      }
    }
    waitMean /= meanSCounter;
    idleMean /= meanWCounter;

    //find median
    if (waitTimesVector.size() % 2 == 0)
    {
      median = (waitTimesVector[waitTimesVector.size() / 2 - 1] + waitTimesVector[waitTimesVector.size() / 2]) / 2;
    }
    else
    {
      median = waitTimesVector[waitTimesVector.size() / 2];
    }

    //get longest wait and idle times
    for (int i = 0; i < studentVector.size(); i++)
    {
      if (studentVector[i].getStudentWaitTime() > longestSWaitTime)
      {
        longestSWaitTime = studentVector[i].getStudentWaitTime();
      }
    }
    for (int i = 0; i < windowVector.size(); i++)
    {
      if (windowVector[i].getWindowIdleTime() > longestWIdleTime)
      {
        longestWIdleTime = windowVector[i].getWindowIdleTime();
      }
    }

    //print results
    cout << "" << endl;
    cout << "Mean Student Wait Time: " << waitMean << endl;
    cout << "Median Student Wait Time: " << median << endl;
    cout << "Longest Student Wait Time: " << longestSWaitTime << endl;
    cout << "Number of Students Waiting Over 10 Minutes: " << numberWaitOver10 << endl;
    cout << "Mean Window Idle Time: " << idleMean << endl;
    cout << "Longest Window Idle Time: " << longestWIdleTime << endl;
    cout << "Number of Windows Idle Over 5 Minutes: " << numberWaitOver5 << endl;
    cout << "" << endl;
}
