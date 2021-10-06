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
  
} 
