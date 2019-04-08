#include "Assignment4.h"
#include <iostream>
#include <vector>

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


//overloaded constructor
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
GenQueue<T>::~GenQueue()
{
  //build some character (figure it out)
}

template <class T>
void GenQueue<T>::insert(T d)
{
  //TODO: error checking isFull

  //circular myQueue
  if(tail == mSize-1)
  {
    tail = -1;
  }

  myQueue[++tail] = d;
  numElements++;
}

template <class T>
T GenQueue<T>::remove()
{
  if (!isEmpty())
  {
    T c = '\0'; //temp varaible set to null variable
    c = myQueue[head];

    //circular myQueue
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
}


//overloaded constructor
Student::Student(int studentID, int neededWTime, int arrivalTime)
{
  this->waitTime = 0;
  this->neededWTime = neededWTime;
  this->atWindow = false;
  this->studentID = studentID;
  this->arrivalTime = arrivalTime;
}

Student::~Student()
{
  //build some character (figure it out)
}

/*void Student::newStudent()
{
  Student s(0,0,0);
}*/

void Student::setStudentID(int studentID)
{
  this->studentID = studentID;
}

void Student::setStudentWindowTime(int neededWTime)
{
  this->neededWTime = neededWTime;
}

void Student::setStudentATime(int arrivalTime)
{
  this->arrivalTime = arrivalTime;
}

void Student::setStudentWaitTime(int waitTime)
{
  this->waitTime = waitTime;
}

void Student::setStudentatWindow(bool atWindow)
{
  this->atWindow = atWindow;
}

int Student::getStudentID()
{
  return studentID;
}

int Student::getStudentWindowTime()
{
  return neededWTime;
}

int Student::getStudentATime()
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

void Student::printSInfo()//(Student student)
{
  cout << "ID: " << studentID << endl;
  cout << "Needed Time: " << neededWTime << endl;
  cout << "Arrival Time: " << arrivalTime << endl;
  cout << "Wait Time: " << waitTime << endl;
  cout << "At Window?: " << atWindow << endl;
}



/////////////////////////////////////////////////////////////////////
Window::Window()
{
  this->idleTime = 0;
  this->studentHere = false;
}

Window::Window(int idleTime)
{
  this->idleTime = idleTime;
  this->studentHere = false;
}

Window::~Window()
{

}

void Window::setWindowIdleTime(int idleTime)
{
  this->idleTime = idleTime;
}

void Window::setWindowStudentHere(bool studentHere)
{
  this->studentHere = studentHere;
}

int Window::getWindowIdleTime()
{
  return idleTime;
}

bool Window::getWindowStudentHere()
{
  return studentHere;
}

void Window::printWInfo()//(Window window)
{
  cout << "Idle Time: " << idleTime << endl;
  cout << "Student Here?: " << studentHere << endl;
}



/////////////////////////////////////////////////////////////////////
Simulation::Simulation()
{
  loop = true;
}

Simulation::Simulation(int something)
{
  loop = true;
}

Simulation::~Simulation()
{

}

void Simulation::Run()
{

  Student s1(0,0,0);
  Student s2(0,0,0);
  Student s3(0,0,0);
  Student s4(0,0,0);
  Student s5(0,0,0);
  Student s6(0,0,0);
  Student s7(0,0,0);
  Student s8(0,0,0);
  Student s9(0,0,0);
  Student s10(0,0,0);
  Student s11(0,0,0);
  Student s12(0,0,0);
  Student s13(0,0,0);
  Student s14(0,0,0);
  Student s15(0,0,0);
  Student s16(0,0,0);
  Student s17(0,0,0);
  Student s18(0,0,0);
  Student s19(0,0,0);
  Student s20(0,0,0);


    /*studentVector.push_back(s1);
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
    studentVector.push_back(s20);*/

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

    /*windowVector.push_back(w1);
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
    windowVector.push_back(w20);*/
  //}

  s3.setStudentID(3);
  s3.setStudentWindowTime(5);
  s3.setStudentATime(1);
  s3.setStudentWaitTime(0);
  s3.setStudentatWindow(true);

  //s3.printSInfo(studentVector[2]);

  //for (int i = 0; i < 20; i++)
  //{
    //studentVector[2]
    s3.printSInfo();
  //}

  //while (loop)
  //{

  //}

}
