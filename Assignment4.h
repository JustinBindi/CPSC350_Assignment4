#include <iostream>
#include <vector>

using namespace std;

template <class T>
class GenQueue
{
  public:
    GenQueue();
    GenQueue(int maxSize);

    void insert (T d);
    T remove();
    T front();

    int getSize();
    bool isFull();
    bool isEmpty();

    int head;
    int tail;
    int numElements;
    int mSize;

    T *myQueue;
};

class Student
{
  public:
    Student();
    Student(int number);

    void printSInfo();
    void setStudentID(int studentID);
    void setStudentWindowTime(int neededWTime);
    void setStudentArrTime(int arrivalTime);
    void setStudentWaitTime(int waitTime);
    void setStudentatWindow(bool atWindow);
    void setStudentTimeAtWindow(int timeAtWindow);
    void setStudentDone(bool studentDone);
    int getStudentID();
    int getStudentWindowTime();
    int getStudentArrTime();
    int getStudentWaitTime();
    bool getStudentatWindow();
    int getStudentTimeAtWindow();
    bool getStudentDone();

    int waitTime;
    int neededWTime;
    bool atWindow;
    int studentID;
    int arrivalTime;
    int timeAtWindow;
    bool studentDone;
};

class Window
{
  public:
    Window();
    Window(int idleTime);

    void printWInfo();
    void setWindowIdleTime(int idleTime);
    void setWindowStudentHere(bool studentHere);
    void setWindowOpen(bool open);
    void setWindowWhichStudentHere(int whichStudent);
    int getWindowIdleTime();
    bool getWindowStudentHere();
    bool getWindowOpen();
    int getWindowWhichStudentHere();

    int idleTime;
    bool studentHere;
    bool open;
    int whichStudent;
};

class Simulation
{
  public:
    Simulation();
    Simulation(bool loopCondition);

    void Run(string fileName);

    bool loop;
    int clock;
    string line;
    int deleter;
    int studentCounter;
    int doneCounter;
    int waitMean;
    int idleMean;
    int median;
    int longestSWaitTime;
    int longestWIdleTime;
    int numberWaitOver10;
    int numberWaitOver5;
    int meanSCounter;
    int meanWCounter;
    vector<int> fileRead;
    vector<Window> windowVector;
    vector<Student> studentVector;
    vector<int> waitTimesVector;
    vector<int> idleTimesVector;
    vector<Student> doneStudents;
};
