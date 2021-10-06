#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;
using TX=long;

const int nElem = 20;
TX vect[nElem] = {5,30,40, 7,80, 90, 37,25, 54,47, 
                  -8, 6, 12, 8, 25, 27, 19, 83, 999, 17};

int main(){
  Node *list = NULL;
  int dato;
  auto a = 0;
  for(int x = 0; x < nElem ; x++ ){
    auto a = vect[x];
    inserlist(list, a);
  }
    cout <<"Esta es la lista\n";  
    while (list != NULL){
     cout<< list-> dato <<" ";
     list = list -> next;
  }
    for(int x = 0; x < nElem ; x++ ){
    auto a = vect[x];
    inserlist(list, a);
  }
    cout << "\nDigite un numero ";
    cin>>a;
    inserlist(list, a);
  
   while (list != NULL){
     cout<< list-> dato <<" ";
     list = list -> next;
  }
  return 0;
}