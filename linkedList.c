#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};

void displayLinkedList(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node *));
    second = (struct Node *) malloc(sizeof(struct Node *));
    third = (struct Node *) malloc(sizeof(struct Node *));

    head->data = 12;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 16;
    third->next = NULL;

    displayLinkedList(head);
return 0;
}