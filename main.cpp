/*Pregunta1

Escriba un programa que defina una Linked List e implemente un método que haga un intercambio entre cada dos nodos adyacentes. Observación: No debes modificar los valores en los nodos de la Linked List (Jesus Gavancho)*/

#include <iostream>
#include "type.h"

using namespace std;


class Node{
  public:
  T1 data;
  Node* next;
};

void IntercambioNodo(Node *head){
  Node* temp=head;
  while(temp !=NULL && temp ->next !=NULL){
    swap(temp->data,temp->next->data);
    //mover temp por 2 nodos adyacentes
    temp=temp->next->next;
  }
}

//adding
void push(Node** head_refer, T1 new_data){
  Node* new_node= new Node();
  new_node->data=new_data;
  new_node->next=(*head_refer);
  (*head_refer)=new_node;
}
//print
void PrintList(Node* node){
  while(node !=NULL){
    cout << node->data << " ";
        node = node->next;
  }
}

int main(){

  Node* start=NULL;

  //MyList

  push(&start,1);
  push(&start,9);
  push(&start,8);
  push(&start,56);
  push(&start,70);
  push(&start,14);
  push(&start,21);
  push(&start,66);
  push(&start,3);
  push(&start,55);

cout<<"Linkedlist antes de realizar el intercambio de nodos cada 2 :"<<endl;cout<<endl;
PrintList(start);
cout<<endl;
cout<<endl;
cout<<"Linkedlist despues de realizar el intercambio de nodos cada 2 :"<<endl;cout<<endl;
IntercambioNodo(start);
PrintList(start);

};