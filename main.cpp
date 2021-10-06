#include <iostream>
#include "type.h"
#include "queue.h"
#include "linkedlist.h"
#include "operators.h"

using namespace std;

const int cantidad = 4;

int main()
{
  TX n1,n2,aux;
  TX vect[cantidad] = {7,42,59,70};
  LinkedList<TX> mylist;
  for(auto x=0; x<cantidad; x++)
  {   mylist.insert_at_tail(vect[x]);
  }
  LinkedList<TX>::iterator iter = mylist.begin();
  for(; iter != mylist.end() ; ++iter)
  {
      cout<< *iter <<endl;
  }
  cout << "Escribe la primera posición a cambiar: ";
  cin >> n1;
  cout << "Escribe la segunda posición a cambiar: ";
  cin >> n2;
  aux=vect[n1];
  vect[n1]= vect[n2];
  vect[n2] = aux;
  for(auto x=0;x<cantidad;x++){
    cout<<vect[x]<<endl;
  }
}