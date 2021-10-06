#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "doublylinkedlist.h"

using namespace std;
template <typename T>
class Stack
{
  private:
    DoublyLinkedList<T> m_list; 
  public:
    Stack() {}
    void push(T n)      {   m_list.push_front(n);   }
    T pop()             {   return m_list.PopHead();    }
};

#endif