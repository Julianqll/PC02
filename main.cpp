#include <iostream>
#include <vector>
#include "doublelinkedlist.h"
using namespace std;



using TX=long;
template <typename T>
void insert(T x);
void viewI();
template <typename T>
void searchposition1(T num);
template <typename T>
void searchposition2(T num);
void viewF();
Node *I, *B, *Y;

const int nElem = 10;
TX vect[nElem] = { 6, 12, 8, 25, 27, 19, 83,-8, 999, 17};

int main(){
  auto num = 0;
  for (int x=0; x<nElem;x++)
  {
    insert(vect[x]);
  }
  cout<<endl<<"Lista"<<endl;

  viewI();

  cout<<endl<<"Buscar numero: ";
  cin>> num;

  searchposition1(num);

  cout<<"lista invertida: "<<endl;
  viewF();
  searchposition2(num);
  return 0;
}

template <typename T>
void insert(T x)
{
    Y = new Node();
    Y->dato=x;
    Y->next =NULL;
    Y->back =NULL;

      if (I==NULL){

         I=Y;
      }else{

        B->next = Y;
        Y->back = B;

      }B=Y;
}

void viewI(){
    Y=I;
  while (Y!=NULL){

    cout << Y->dato <<" ";
    Y = Y->next;
    
  }
}


template <typename T>
void searchposition1(T num)
{
  Y=I;
  auto i=0;
  while (Y!=NULL)
  {
      i++;

      if (Y->dato==num)
      {
        break;
      }
    Y = Y->next;
  }
  cout  <<"La posición es: "<< i <<endl<<endl;
}

template <typename T>
void searchposition2(T num){
  
  Y=B;
  int j=0;
    while (Y!=NULL)
    {
      j++;

      if (Y->dato==num){
        break;
      }

      Y = Y-> back;
    }
  cout<<endl << "La nueva posición: "<< j <<endl<<endl;
}

void viewF(){
  Y=B;
  while (Y!=NULL){
    cout << Y->dato <<" ";
    Y = Y->back;
  }
}