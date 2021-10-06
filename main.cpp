/*Pregunta4
Escriba un programa que defina una Doubly Linked List de números enteros ordenada e implemente un método que pida un elemento de la lista y luego invierta la lista para así imprimir la posición original del elemento, la nueva posición del elemento y la lista invertida (Jesus Gavancho)*/

#include <iostream>
#include <vector>
#include "type.h"
#include "stack.h"
#include "queue.h"
#include "doublylinkedlist.h"
#include "operators.h"
#include "operacion.h"

using namespace std;

const TX nElem = 10;
TX vect[nElem] = {2,3,7,18,22,31,46,51,77,85};

void fx(TX &x)
{  cout << x << "  "; }

void inc(TX &x)
{  ++x; }

template <typename Iterator, typename F>
void recorrer(Iterator ItBegin, Iterator ItEnd, F ope)
{
  Iterator iter = ItBegin;
  for(; iter != ItEnd ; ++iter)
      ope(*iter);
}
// #1
template <typename Container, typename F>
void recorrer(Container &container, F ope)
{ recorrer(container.begin(), container.end(), ope);
}

// TODO implementar el recorrer inverso
// # 2
template <typename Container, typename F>
void recorrer_inverso(Container &container, F ope)
{ recorrer(container.rbegin(), container.rend(), ope);
}

template <typename Container>
void recorrer(Container &container)
{
    recorrer(container, fx);  cout << endl; // recorre imprimiendo
    recorrer(container, inc);  // recorre incrementando
    recorrer(container, fx);  cout << endl; // recorre imprimiendo
    // funciones lambda
    recorrer(container, [](TX &n){ n-= 5;}); cout << endl; // -5 a todos
    recorrer(container, fx);  cout << endl; // recorre imprimiendo
    OperacionEspecial<TX> ope;
    recorrer(container, ope);  
    recorrer(container, fx);  cout << endl;
}

void demoLinkedListSorted()
{
  TX FirstData;
  DoublyLinkedList<TX> mylist;
  //print
  cout<<"My doublylinkedlist es: ";cout<<endl;
  for(auto x=0; x<nElem; x++)
  {   cout << "> " << vect[x] << endl; 
      mylist.insert(vect[x]);
  }
  
  cout<<"Pls escribir algun numero de la lista para ver su posicion en la misma! "<<endl;
  cin >> FirstData;
  for(auto x=0;x<nElem;x++){
    if(FirstData==vect[x]){
      cout<<"Se ubica en la : "<<x<<" posicion de la lista!"<<endl;
    }
}
cout<<endl;
cout << "Mydoublylinkedlist sorted: "<<endl;
recorrer(mylist, fx);  cout << endl;

for(auto x=0;x<nElem;x++){
    if(FirstData==vect[x]){
      cout<<"Ahora  en Mydoublylinkedlist sorted invertida se ubica en la  : "<< (nElem-1)  - x <<" posicion de la lista!"<<endl;
    }
}
recorrer_inverso(mylist, fx);  cout << endl;
}

int main(){

vector<TX> v1;
  demoLinkedListSorted();
  cout << "Finalizando el programa ..." << endl;

}
