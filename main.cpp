#include <iostream>
#include "type.h"
#include "doublelinkedlist.h"
//by jose terrones
using namespace std;

const TX nElem = 10;
TX main()
{
  TX valores[nElem] = {10, 20, 30, 40, 50, 60, 70, 80, 85, 90};
  DoubleLinkedList<TX> Prueba;
  cout<< "Proceso de Insercion"<<endl;
  for(auto x=0; x<nElem; x++)
  {
      Prueba.insert_at_tail(valores[x]);
      Prueba.print(cout);
  }
  cout<<endl<< "Double Linked List"<<endl;
  Prueba.print(cout);

} 

