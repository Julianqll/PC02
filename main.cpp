
#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;
using TX=long;

const int nElem = 6;
TX vect[nElem] = {1,2,5,6,8,9};

int main(){
  Node *list = NULL;
  int dato;
  auto num_ins = 0;
  for(auto num = 0; num < nElem ; num++ ){
    auto num_ins= vect[num];
    inserlist(list, num_ins);
  }
    cout <<"Lista actual\n";  
    while (list != NULL){
     cout<< list-> dato <<" ";
     list = list -> next;
  }
    for(auto nume = 0; nume < nElem ; nume++ ){
    auto num_ins = vect[nume];
    inserlist(list, num_ins);
  }
    cout << "\nInserte un numero ";
    cin>>num_ins;
    inserlist(list, num_ins);
  
   while (list != NULL){
     cout<< list-> dato <<" ";
     list = list -> next;
  }
  return 0;
}