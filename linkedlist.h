#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node{
  int dato;
  Node *next;
};

void inserlist(Node *&list, int n){
  Node *new_node = new Node();
  new_node -> dato = n;

  Node *aux1 = list;
  Node *aux2;

  while ((aux1 != NULL) && (aux1 -> dato <n)){
    aux2 = aux1;
    aux1 = aux1->next;
  }
  if (list == aux1){
    list = new_node;
  }else{
    aux2 -> next = new_node;
  }
  new_node -> next =aux1;
}

#endif