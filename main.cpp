#include <iostream>
#include "type.h"
#include "doublelinkedlist.h"
//by jose terrones
using namespace std;

const TX nElem = 10;
TX main()
{
  TX valores[nElem] = {50, 20, 10, 96, 27, 15, 39, 24, 5, 74};
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

