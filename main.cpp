#include <iostream>
#include <vector>
#include "type.h"
#include "linkedlist.h"
#include "operators.h"
#include "operacion.h"
using namespace std;

const int nElem = 20; //numero de elementos

TX vect[nElem] = {5,30,40, 7,80, 90, 3,25, 54,47,3,6,12,8,25,27,19,83,9,0};

template <typename T>
void swap1(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
void demoSwap()
{
  int x = 5, y = 9;
  cout << "x=" << x << ", y=" << y <<endl;
  swap1(x, y);
  cout << "x=" << x << ", y=" << y <<endl;

  double w = 7.3, z = 14.8;
  cout << "w=" << w << ", z=" << z <<endl;
  swap1(w, z);
  cout << "w=" << w << ", z=" << z <<endl;
}


void fx(TX &x)
{  cout << x << "  "; }

void inc(TX &x)
{  ++x; }

template<typename Container, typename F>
void recorrer(Container &container, F fobj) 
{ 
  typename Container::iterator iter = container.begin();
  for(; iter != container.end() ; ++iter)
  {
     fobj(*iter);
  }
}

template <typename Container>
void recorrer(Container &container)
{
    recorrer(container, fx);  cout << endl; 
    recorrer(container, inc);  
    recorrer(container, fx);  cout << endl; 
    recorrer(container, [](TX &n){ n-= 5;}); cout << endl; 
    recorrer(container, fx);  cout << endl; 
    OperacionEspecial<TX> ope;
    recorrer(container, ope);  
    recorrer(container, fx);  cout << endl;
}

void demoLinkedList()
{
  vect[10] = 53;
  int z=5;
  LinkedList<TX> mylist;
  for(auto x=0; x<10; x++)
  {   mylist.insert_at_tail(vect[x]);
      cout << mylist<<" . "<< z <<endl;
      cout <<endl;
  }
  cout << endl;
  for(auto x=10; x< nElem; x++)
  {   mylist.insert_at_head(vect[x]);
      cout << mylist <<endl;
  }
  auto x1 = mylist[7];
  mylist[5] = 14;
  cout << endl;
  recorrer(mylist);
}

void demoLinkedListSorted(){ //ordenar la lista
  LinkedList<TX> mylist;
  TX  f=6; //Valor
  TX s=2; //posicion
  vect[s]=f; //Ingresamos el numero que correspone
  for(auto x=0; x<10; x++)//primero 10 primeros por cola
  {   
    cout << "> " << vect[x] <<endl;
    mylist.insert_2(vect[x]);//insertamos en la cola 
    recorrer(mylist, fx);  cout << endl;
  }
  cout<< "Numero que ingreso: "<<f<<endl; 
    cout<< "Posición donde ingreso: "<<s<<endl; 
}

int main()
{


  vector<TX> v1;
  demoLinkedListSorted();
  cout << "Finalizando el programa ..." << endl;

}