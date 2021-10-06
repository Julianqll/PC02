#include <iostream>
#include "type.h"
#include "doublelinkedlist.h"
//by jose terrones
using namespace std;

const TX nElem = 10;
TX main()
{
  TX valores[nElem] = {64, 25, 84, 70, 19, 57, 39, 46, 30, 50};
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
