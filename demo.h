#include <iostream>
#include <vector>
#include "type.h"
#include "linkedlist.h"
#include "recorrer.h"
using namespace std;

const TX nElem = 10;

TX vect[nElem] = {4,6,1,8,9,3,5,10,2,7};

void demoLinkedListSorted()
{
  LinkedList<TX> mylist;
  cout<<"LISTA ORDENADA"<<endl;
  for(TX x=0; x<nElem; x++)
  { 
      mylist.insert_2(vect[x]);
  }
  recorrer(mylist, fx); 
  cout << endl;

}
