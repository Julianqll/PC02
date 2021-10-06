/*Pregunta6

Escriba un programa que defina una Doubly Linked List con elementos repetidos e implemente un método que elimine los nodos duplicados (Jesus Gavancho)*/

#include <iostream>
#include "type.h"

using namespace std;

struct Node{
    T1 data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_refer, struct Node* dele)
{
  if (*head_refer == NULL || dele == NULL)
        return;
        if (*head_refer == dele)
        *head_refer = dele->next;
  if (dele->next != NULL)
        dele->next->prev = dele->prev;
  if (dele->prev != NULL)
        dele->prev->next = dele->next;  
        free(dele);
}

void RemoveDuplicado(struct Node** head_refer){
  //si hay solo 1 element or is empty
    if ((*head_refer) == NULL ||
        (*head_refer)->next == NULL)
        return;
 
    struct Node* ptr1, *ptr2;

  for (ptr1 = *head_refer; ptr1 != NULL; ptr1 = ptr1->next) {
        ptr2 = ptr1->next;
        //comparar elementos
  while (ptr2 != NULL) {
    //si hay borrarlos
    if (ptr1->data == ptr2->data) {
      struct Node* next = ptr2->next;
      deleteNode(head_refer, ptr2);
      ptr2 = next;
}
else
                ptr2 = ptr2->next;
        }
    }
}

//insertando en DoublyLinkedList
void push(struct Node** head_refer, int new_data)
{
  struct Node* new_node =
        (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->prev = NULL;
        new_node->next = (*head_refer);
  if ((*head_refer) != NULL)
    (*head_refer)->prev = new_node;
(*head_refer) = new_node;
}
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct Node* head = NULL;
    //MyList
    push(&head, 11);
    push(&head, 11);
    push(&head, 5);
    push(&head, 3);
    push(&head, 6);
    push(&head, 3);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 9);
    push(&head, 9);

    cout<<"Original Doubly Linked List: "<<endl;cout<<endl;
    printList(head);
    cout<<endl;cout<<endl;

    cout<<" Doubly Linked List despues de utilizar el metodo de borrar duplicados: "<<endl;cout<<endl;

    RemoveDuplicado(&head);
    printList(head);
    cout<<endl;cout<<endl;        
       
}