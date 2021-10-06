/*Pregunta5

Escriba un programa que defina una Doubly Linked List e implemente un método que busque por la lista a un elemento en específico. Si el elemento fue encontrado, entonces el método retornará Verdadero; de lo contrario, devolverá Falso.(Jesus Gavancho)
*/

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
//verificando si el valor x esta presente in the DoublyLinkedList
bool search(Node* head, T1 x) 
{ 
  //initializing
    Node* current = head;  
    while (current != NULL) 
    { 
        if (current->data == x) 
            return true; 
        current = current->next; 
    } 
    return false; 
} 


//insertando en DoublyLinkedList
void push(struct Node** head_refer, int new_data)
{
  struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
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
    //initializing number of element with 77 just to check it!
    T1 x=77;//change here with the other elements in order to search
    //MyList
    push(&head, 11);
    push(&head, 19);
    push(&head, 9);
    push(&head, 8);
    push(&head, 77);

    
    cout<<"My DoublyLinkedList"<<endl;cout<<endl;
    printList(head);cout<<endl;cout<<endl;
    cout<<"Verificacion del numero inicializado antes(77) si ha sido encontrado"<<endl;cout<<endl;
    //using ternary
    search(head, 77)? cout<<"Verdadero" : cout<<"Falso";
    cout<<endl;         
       
}