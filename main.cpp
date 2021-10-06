#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;
using TX=long;
const int nElem = 20;
TX vect[nElem] = {5,30,40, 7,80, 90, 37,25, 54,47, 
                  -8, 6, 12, 8, 25, 27, 19, 83, 999, 17};

int main(){
  Node *list0 = NULL;
  int dato;
  auto num_ins = 0;
  for(auto num = 0; num < nElem ; num++ ){
    auto num_ins= vect[num];
    inserlist(list0, num_ins);
  }
  cout <<"Lista con los datos adyacentes cambiados\n";  
    while (list0 != NULL){
      
      cout<<list0->next->dato<<" " << list0->dato <<" ";
      list0 = list0->next->next;
      
  }
  
  return 0;
}