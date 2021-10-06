#ifndef __OPERATORS_H__  
#define __OPERATORS_H__ 

#include <iostream>
#include "doublelinkedlist.h"
#include "queue.h"
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, DoubleLinkedList<T> &container)
{
    return container.print(os);
}

template <typename T>
ostream &operator<<(ostream &os, Queue<T> &container)
{
    return container.print(os);
}

#endif