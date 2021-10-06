#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;
using TX=long;

const int nElem = 10;
TX vect[nElem] = { 12,6, 8, 25, 27, 19, 83, 999, 17};

int main(){
  Node *list0 = NULL;
  int dato;
  auto numins = 0;
  for(auto num = 0; num < nElem ; num++ ){
    auto numins= vect[num];
    inserlist(list0, numins);
  }
  cout <<"Lista con cambios adyacentes \n";  
    while (list0 != NULL){
      
      cout<<list0->next->dato<<" " << list0->dato <<" ";
      list0 = list0->next->next;
      
  }
  
  return 0;
}
