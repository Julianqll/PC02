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
template <typename T>
void compr(T num);
bool print = false;
void viewF();
Node *I, *F, *R;

const int nElem = 20;
TX vect[nElem] = {5,30,40, 7,80, 90, 37,25, 54,47, 
                  -8, 6, 12, 8, 25, 27, 19, 83, 999, 17};

int main(){
  auto num = 0;
  for (int x=0; x<nElem;x++){
    insert(vect[x]);
  }
  cout<<"Esta es la lista"<<endl;
  viewI();
  cout<<"\nInserte el numero a buscar: ";
  cin>> num;
  compr(num);
  if (print == true){
  searchposition1(num);
  cout<<"La lista invertida es"<<endl;
  viewF();
  searchposition2(num);
  }else {
    cout <<"El valor no existe en la lista"<<endl;
  }
  return 0;
}

template <typename T>
void insert(T x){
  R = new Node();
  R->dato=x;
  R->next =NULL;
  R->back =NULL;
  if (I==NULL){
    I=R;
  }else{
    F->next = R;
    R->back = F;
  }F=R;
}

template <typename T>
void compr(T num){
  while (R!=NULL){
    R=I;
  if (R==NULL){
    print = true;
    break;
  }
  R = R->next;
  }
}

void viewI(){
  R=I;
  while (R!=NULL){
    cout << R->dato <<" ";
    R = R->next;
  }
}


template <typename T>
void searchposition1(T num){
  R=I;
  int i=0;
  while (R!=NULL){
    i++;
    if (R->dato==num){
      break;
    }
    R = R->next;
  }
  cout  <<"La posición del objeto es: "<< i <<endl;
}

template <typename T>
void searchposition2(T num){
  R=F;
  int j=0;
  while (R!=NULL){
    j++;
    if (R->dato==num){
      break;
    }
    R = R-> back;
  }
  cout << "\nLa nueva posición del objeto es: "<< j <<endl;
}

void viewF(){
  R=F;
  while (R!=NULL){
    cout << R->dato <<" ";
    R = R->back;
  }
}