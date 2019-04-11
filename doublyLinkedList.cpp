#include <iostream>

using namespace std;

template <class T>
class ListNode
{
  public:
    ListNode();
    ListNode(T d);
    T data;
    ListNode *next;
    ListNode *prev;
};

template <class T>
ListNode<T>::ListNode()
{
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <class T>

ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
class DoublyLinkedList
{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
  public:
    DoublyLinkedList();
    void insertFront (T d);
    void insertBack (T d);
    int removeFront();
    ListNode<T>* remove(int key);
    void printList();
    int find(T d); //search method
    T deletePos(int pos);
    bool isEmpty;
    unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  front = NULL;
  size = 0;
  back = NULL;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T> *curr = front;

  while(curr)
  {
    cout << curr->data << endl;
    curr = curr-next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0)
  {
    back = node;
  }
  else
  {
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0)
  {
    back = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
int DoublyLinkedList<T>::removeFront()
{
  T temp = front->data;
  ListNode<T> *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

template <class T>
ListNode<T>* DoublyLinkedList<T>::remove(int key)
{
  ListNode<T> *curr = front;
  while (curr->data != key)
  {
    curr = curr->next;

    if (curr == NULL)
    {
      return NULL;
    }
  }

  if (curr == front)
  {
    front = curr->next;
  }
  else
  {
    curr->prev->next = curr->next;
  }

  if (curr = back)
  {
    back = curr->prev;
  }
  else
  {
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;

  size--;

  return curr;
}

template <class T>
int DoublyLinkedList<T>::find(T d)
{
  int idx = -1;
  ListNode<T> *curr = front;

  while (curr != NULL)
  {
    ++idx;
    if (curr->data = d)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
  {
    idx = -1;
  }
  return idx;
}

template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos)
  {
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  prev->next = curr->next;
  curr->next = NULL;
  T temp = curr->data;
  size--;

  return temp;
}
