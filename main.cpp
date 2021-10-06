#include <iostream>
#include <vector>
#include "doublelinkedlist.h"
using namespace std;
using TX=long;
template <typename T>
void insert(T x);
void viewI();
void viewF();
template <typename T>
void search(T num);
bool esta = false;
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
  search(num);
  if (esta==true){
    cout << "El objeto si se encuentra en la lista"<<endl;
  }else{
    cout <<"No se ha encontrado el obejto"<<endl;
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

void viewI(){
  R=I;
  while (R!=NULL){
    cout << R->dato <<" ";
    R = R->next;
  }
}
template <typename T>
void search(T num){
  R=I;
  int i;
  while (R!=NULL){
    if (R->dato == num){
      esta = true;
    }
    R = R->next;
    }
}
