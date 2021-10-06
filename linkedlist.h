#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node{
  int dato;
  Node *next;
};

void inserlist(Node *&list0, int n){
  Node *new_node = new Node();
  new_node -> dato = n;

  Node *aux1 = list0;
  Node *aux2;
  

  while ((aux1 != NULL) ){
    aux2 = aux1;
    aux1 = aux1->next;
    
  }
  if (list0 == aux1){
    list0 = new_node;
  }else{
    aux2 -> next = new_node;
  }
  new_node -> next =aux1;
}

#endif