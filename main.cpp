/*Pregunta3:
Escriba un programa que defina una Linked List de números enteros ordenada e implemente un método que pida dos elementos de la lista y realice un intercambio entre ellos, para que finalmente, retorne la Linked List con el nuevo cambio. Observación: No debes modificar los valores en los nodos de la Linked List.(Jesus Gavancho)*/


#include <iostream>
#include "type.h"
#include "queue.h"
#include "linkedlist.h"
#include "operators.h"

using namespace std;

const T1 nElem=10;
int main(){
  T1 FirstData,SecondData,key;
  T1 vect[nElem]={19,9,8,21,12,6,5,11,10,2};
  LinkedList<T1> mylist;
  //print
  for(auto x=0; x<nElem; x++)
  {   mylist.insert_at_tail(vect[x]);
  }
   LinkedList<T1>::iterator iter = mylist.begin();
  for(; iter != mylist.end() ; ++iter)
  {
      cout<< *iter <<endl;
  }
  cout<<endl; cout<<"Pls ecribir la  1st posicion de la lista a cambiar:"<<endl;
  cin>>FirstData;cout<<endl;
  cout<<"Pls ecribir la 2nd posicion de la lista a cambiar:"<<endl;
  cin>>SecondData;cout<<endl;
  key=vect[FirstData];
  vect[FirstData]=vect[SecondData];
  vect[SecondData]=key;
  //print
  for(auto x=0;x<nElem;x++){
    cout<<vect[x]<<endl;
  }

}
