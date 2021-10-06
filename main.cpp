#include <iostream>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}
 
void insertBefore(struct Node** head_ref,
                  struct Node* next_node, int new_data)
{
    if (next_node == NULL) {
        cout <<"no puede ser NULL";
        return;
    }
 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data = new_data;
 
    new_node->prev = next_node->prev;
 
    next_node->prev = new_node;
 
    new_node->next = next_node;
 
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head_ref) = new_node;
}
 
void printList(struct Node* node)
{
    struct Node* last;
    cout <<"\nNumeros Enteros \n";
    while (node != NULL) {
        cout <<"  "<< node->data;
        last = node;
        node = node->next;
    }
 
    cout <<"\nInvertido \n";
    while (last != NULL) {
        cout <<"  "<< last->data;
        last = last->prev;
    }
}
 
int main()
{
    struct Node* head = NULL;
    push(&head, 2);
 
    push(&head, 1);
 
    push(&head, 4);
 
    insertBefore(&head, head->next, 3);
 
    printList(head);
 
    getchar();
    return 0;
}