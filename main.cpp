#include <bits/stdc++.h>
using namespace std;

struct Node {

	int data;

	Node* next;

	Node* prev;
};

void push(Node** head_ref, int new_data)
{

	Node* new_node
		= (Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL) {

		(*head_ref)->prev = new_node;
	}

	(*head_ref) = new_node;
}

int search(Node** head_ref, int x)
{

	Node* temp = *head_ref;

	int pos = 0;

	while (temp->data != x
		&& temp->next != NULL) {

		pos++;

		temp = temp->next;
	}

	if (temp->data != x)
		return false;

	return (pos + 1);
}

int main()
{
	Node* head = NULL;
	int X = 8;

	push(&head, 6);
	push(&head, 32);
	push(&head, 96);
	push(&head, 10);
	push(&head, 7);

	cout << search(&head, X);

	return 0;
}
