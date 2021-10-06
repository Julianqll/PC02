#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include "linkedlist.h"

using namespace std;

template <typename T>
class Queue
{
  private:
    LinkedList<T> m_list;
    
  public:
    Queue();
    void insert(T n);
    T pop();
    ostream &print(ostream &os);
    size_t size() {   return m_list.size();   }
};

template <typename T>
Queue<T>::Queue()
{

}

template <typename T>
void Queue<T>::insert(T n)
{
    m_list.insert_at_tail(n);
}

template <typename T>
T Queue<T>::pop()
{
  return m_list.PopHead();
}

template <typename T>
ostream &Queue<T>::print(ostream &os)
{   return m_list.print(os);
}

#endif
