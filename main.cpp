#include <iostream>
#include <vector>
#include "doublelinkedlist.h"
using namespace std;
using TX=long;
template <typename T>
void insert(T x);
void elim();
void viewI();
Node *I, *F, *R, *borrar;

const int nElem = 10;
TX vect[nElem] = {5,30,30, 80,80, 90, 90, 25, 25,47};

int main(){

  auto num = 0;
  for (int x=0; x<nElem;x++){
    insert(vect[x]);
  };
  cout<<"La lista sin los valores repetidos"<<endl;
  elim();
  viewI();
  return 0;
};

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
};

void elim(){
  R=I;
  Node *aux = NULL;
  while (R!=NULL){
    R = R->next;
    while (borrar!=NULL){
      borrar = R->next;
      if (R->dato == borrar->dato){
        borrar = R->next;
        aux = borrar ->back;
        delete aux;
      }else{
        R = R->next;
      }
    }
  }
};

void viewI(){
  R=I;
  while (R!=NULL){
    cout << R->dato << " ";
    R = R->next;
  };
};