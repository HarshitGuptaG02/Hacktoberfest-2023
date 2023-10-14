#include<iostream>
using namespace std;

struct Node
{
  int num;
  struct Node *next;
} *head;

void insertStart (struct Node **head, int data)	//function to create linked list
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->num = data;

  // if its the first node being entered
  if (*head == NULL)
    {
      *head = newNode;		// assigning itself as head
      (*head)->next = *head;	// assigning itself as next node

      cout << newNode->num << " Inserted\n";
      return;
    }

  // if CLL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    {
      curr = curr->next;
    }

  curr->next = newNode;		// last node's next as this new node
  newNode->next = *head;	// new node's next as current head node

  *head = newNode;		// changing head node to this new node
  cout << newNode->num << " Inserted\n";

  // previous head node becomes 2nd node
}

void display (struct Node *head)
{

  //cout << "\nCircular Linked List : " << endl;

  // if circular linked list is empty currently
  if (head == NULL)
    return;

  struct Node *temp = head;

  // since we need to take care of circular nature of linked list
  do
    {
      cout << temp->num << " ";
      temp = temp->next;

    }
  while (temp != head);
  cout << endl;
}

int count (struct Node *head)	//function to count number of nodes
{
  int cnt = 0;
  struct Node *cur = head;

  //Iterating till end of list
  do
    {
      cur = cur->next;
      cnt++;
    }
  while (cur != head);

  return cnt;
}

int main ()				//main function
{
  head = NULL;

  insertStart (&head, 1);
  insertStart (&head, 2);
  insertStart (&head, 3);
  insertStart (&head, 4);
  insertStart (&head, 5);
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;
  cout << "\nCircular linked list data:\n";
  display (head);
  cout << "\nTotal number of nodes are: " << count (head);
}
