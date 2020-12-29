//206. Reverse Linked List
#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int val)
{
    Node *node = (Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}
void reverseLinkedList(Node **head)
{
    Node *prev = NULL;
    Node *curr = *head;
    while (curr)
    {
        Node *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    *head = prev;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void push(Node **head, int data)
{
    Node *new = newNode(data);
    new->next = *head;
    *head = new;
}
int main()
{
    Node *head = NULL;
    push(&head, 12);
    push(&head, 24);
    push(&head, 38);
    push(&head, 29);

    printList(head);
    reverseLinkedList(&head);
    printList(head);

    return 0;
}
