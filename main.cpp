#include <iostream>
#include <vector>
#include "type.h"
#include "stack.h"
#include "queue.h"
#include "doublelinkedlist.h"
#include "operators.h"
#include "operacion.h"

using namespace std;

const int cantidad = 8;
TX vect[cantidad] = {11,15,12,12,30,30,15,37};
TX repetido[cantidad];

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
  DoubleLinkedList<TX> mylist;
  for(auto x=0; x<cantidad; x++)
  {   cout << "> " << vect[x] << endl; 
      mylist.insert(vect[x]);
  }
  cout << "Lista en orden: ";
  recorrer(mylist, fx);  cout << endl;
  cout << "Lista invertida: ";
  recorrer_inverso(mylist, fx);  cout << endl;
  cout << "lista no repetida: "<<endl;
  
  for(auto x=0;x<cantidad;x++){
    TX val=vect[x];
    repetido[0]=false;
    if(repetido[x]!=true){
      cout<<vect[x] <<endl;
    }
    for(auto i=x++;i<cantidad;i++){
      if(vect[i]==val){
        repetido[i]=true;
      }
    }
  }
}

int main()
{
  vector<TX> v1;
  demoLinkedListSorted();
  cout << "Finalizando el programa ..." << endl;
}