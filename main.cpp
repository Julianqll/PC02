#include <iostream>
#include <vector>
#include"linkedlist.h"
#include"type.h"
using namespace std;

const int cant=6;
int main() {
 RX vect[cant]={1,2,3,4,5,6};

  LinkedList<RX> mylist;     
  RX n;
  cout<<"Ingrese la posición entre 1 al 5:"<<endl;
  cin>>n; 
   mylist.Intercambio(n);
   

}