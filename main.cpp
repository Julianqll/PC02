#include <iostream>
#include <vector>
#include "type.h"
#include "doublelinkedlist.h"
#include "operators.h"
#include "operacion.h"
using namespace std;

const int nElem = 20; //numero de elementos

TX vect[nElem] = {5,30,40, 7,80, 90, 3,25, 54,47,4,6,12,8,25,27,19,83,9,17};

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

//generalizar los recorridos
template< typename Iterator,typename F>
void recorrer( Iterator ItBegin, Iterator ItEnd, F ope) 
{ 
  Iterator iter = ItBegin;
  for(; iter != ItEnd; ++iter)
  {
     ope(*iter);
  }
}


template<typename Container, typename F>
void recorrer(Container &container, F ope) 
{ 
  recorrer(container.begin(), container.end(), ope);
}

//Inverso
template<typename Container, typename F>
void recorrer_inverso(Container &container, F ope) 
{ 
  recorrer(container.rbegin(), container.rend(), ope);
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

void demoDoubleLinkedList()
{
  vect[10] = 53;
  int z=5;
  DoubleLinkedList<TX> mylist;
  for(auto x=0; x<10; x++)
  {   mylist.push_back(vect[x]);
      cout << mylist<<" . "<< z <<endl;
      cout <<endl;
  }
  cout << endl;
  for(auto x=10; x< nElem; x++)
  {   mylist.push_front(vect[x]);
      cout << mylist <<endl;
  }
  auto x1 = mylist[7];
  mylist[5] = 14;
  cout << endl;
  recorrer(mylist);
}

void demoDoubleLinkedListSorted(){ //ordenar la lista
  DoubleLinkedList<TX> mylist;
  TX f = 6;//Ingresamos el numero que corresponde en la posicion que desean
  TX s = 2; //posicion donde quiere que ingrese
  vect[s]=f;

  for(auto x=0; x<nElem; x++)//primero 10 primeros por cola
  {   
    cout << "> " << vect[x] <<endl;
    mylist.insert(vect[x]);//insertamos en la cola 
  }
    cout<< "Numero que ingreso: "<<f<<endl; 
    cout<< "Posición donde ingreso: "<<s<<endl; 
    cout<< "Lista en orden: ";
    recorrer(mylist, fx);  cout << endl;
    cout<<"Lista invertida: "<<endl;
    recorrer_inverso(mylist, fx);  cout << endl;
}

int main()
{


  vector<TX> v1;
  demoDoubleLinkedListSorted();
  cout << "Finalizando el programa ..." << endl;

}