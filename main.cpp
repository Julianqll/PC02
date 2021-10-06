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
TX vect[nElem] = { 6, 12, 8,8, 25, 27, 19, 83, 999, 17};

int main(){
  auto num = 0;
  for (int x=0; x<nElem;x++)
  {
    insert(vect[x]);
  }
  cout<<endl<<"Lista"<<endl;

  viewI();

  cout<<"lista sin repetidos: "<<endl;
  viewF();

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



//
  void viewF(){
  Y=B;

  while (Y!=NULL){
    if(Y->back==Y->next)
    cout << Y->dato <<" ";
    Y = Y->back;
    
  }
    
  }