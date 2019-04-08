#include <iostream>
#include <vector>

using namespace std;

template <class T>
class GenQueue
{
  public:
    GenQueue(); //default
    GenQueue(int maxSize); //overloaded constructor
    ~GenQueue(); //destructor

    void insert (T d); //aka enqueue
    T remove(); //aka dequeue()
    T front(); //tells who is at the front of the outline, aka peek()

    int getSize();
    bool isFull();
    bool isEmpty();

    int head; //should be private
    int tail; //
    int numElements;
    int mSize;

    char *myQueue;
};

class Student
{
  public:
    Student(); //default
    Student(int number, int windowTime, int arrTime); //overloaded constructor
    ~Student(); //destructor

    void printSInfo();//(Student student);
    void setStudentID(int studentID);
    void setStudentWindowTime(int neededWTime);
    void setStudentATime(int arrivalTime);
    void setStudentWaitTime(int waitTime);
    void setStudentatWindow(bool atWindow);
    int getStudentID();
    int getStudentWindowTime();
    int getStudentATime();
    int getStudentWaitTime();
    bool getStudentatWindow();

    //void newStudent();

    int waitTime;
    int neededWTime;
    bool atWindow;
    int studentID;
    int arrivalTime;
    //vector<Student> studentVector;
};

class Window
{
  public:
    Window(); //default
    Window(int idleTime); //overloaded constructor
    ~Window(); //destructor

    void printWInfo();//(Window window);
    void setWindowIdleTime(int idleTime);
    void setWindowStudentHere(bool studentHere);
    int getWindowIdleTime();
    bool getWindowStudentHere();

    int idleTime;
    bool studentHere;

};

class Simulation
{
  public:
    Simulation();
    Simulation(int something);
    ~Simulation();

    void Run();

    bool loop;
    //vector<Student> studentVector;
    //vector<Window> windowVector;
};
