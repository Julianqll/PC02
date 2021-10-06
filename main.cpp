#include <iostream>
#include <vector>
#include "demo.h"
using namespace std;


int main()
{
  LinkedList<TX> mylist;
  for(auto x=0; x<nElem; x++)
  {
      mylist.insert_at_tail(vect[x]);
  }
  cout<< "LISTA"<<endl;
  mylist.print(cout);
  cout<<endl;
  cout<<endl;
  demoLinkedListSorted();
  
  LinkedList<TX> mylist2;
  TX  nuevoValor=7; 
  TX nuevaLista=9;
  vect[nuevaLista]=nuevoValor; 
  cout<<endl;
  cout<<"LISTA ORDENADA NUEVA"<<endl;
  for(TX x=0; x<nElem; x++)
  { 
      mylist2.insert_2(vect[x]);
  }
  recorrer(mylist2, fx); 
  cout << endl;
} 
