#include <iostream>
#include "type.h"
#include "queue.h"
#include "linkedlist.h"
#include "operators.h"

using namespace std;

const int cantidad = 8;

int main()
{
  TX vect[cantidad] = {1,2,3,4,5,6,7,8};
  LinkedList<TX> mylist;
  for(auto x=0; x<cantidad; x++)
  {   mylist.insert_at_tail(vect[x]);
  }

  LinkedList<TX>::iterator iter = mylist.begin();
  for(; iter != mylist.end() ; ++iter)
  {
      cout<< *iter <<endl;
  }
cout << "intercambio entre cada dos nodos adyacentes "<<endl ;
  TX aux1,aux2;
  for(auto x=0;x<cantidad;x=x+4){    
    aux1=vect[x];
    vect[x]=vect[x+2];
    vect[x+2]=aux1;
    aux2=vect[x+1];
    vect[x+1]=vect[x+3];
    vect[x+3]=aux2;
  for(auto i=x;i<x+4;i++){
      cout<<vect[i]<< endl; 
    }
  }
}