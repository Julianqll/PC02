#include <iostream>
#include <vector>
#include "type.h"
#include "stack.h"
#include "queue.h"
#include "doublelinkedlist.h"
#include "operators.h"
#include "operacion.h"

using namespace std;

const TX cantidad = 4;
TX vect[cantidad] = {7,42,59,70};

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
  TX valor=0;
  DoubleLinkedList<TX> mylist;
  for(auto x=0; x<cantidad; x++)
  {   cout << "> " << vect[x] << endl; 
      mylist.insert(vect[x]);
  }
  cout << "Lista en orden: ";
  recorrer(mylist, fx);  cout << endl;
  //cout << "Lista invertida: ";
  cout << "La lista ordenada desde pares a impares es: "<<endl;
  for(auto x=0;x<cantidad;x++){
    if(vect[x]%2==0){
      vect[valor]=vect[x];
      
      cout<<vect[valor] <<endl;
          valor++;
    }
    valor=-1;
  }
  for(auto x=0;x<cantidad;x++){
    if(vect[x]%2==1){
      vect[valor]=vect[x];
      cout<<vect[valor] <<endl;  
          valor++;
    }
  } 
  //recorrer_inverso(mylist, fx);  cout << endl;
  
}

int main()
{
  
  vector<TX> v1;
  demoLinkedListSorted();
  cout << "Finalizando el programa ..." << endl;
}