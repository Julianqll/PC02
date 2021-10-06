#include <iostream>
#include "type.h"

#include "linkedlist.h"


using namespace std;

const int nElem = 6;

int main()
{
  TX vect[nElem] = {1,2,3,4,5,6};

  LinkedList<TX> mylist;
  cout<<"Ingrese los numeros:"<<endl;
  TX n;
  TX m;
  cin>> n;
  cin>> m;
  for(auto i=0;i<7;i++){
  if(vect[i]==n || vect[i]==m){
    mylist.Intercambio1(n,m);
  }

  }

}