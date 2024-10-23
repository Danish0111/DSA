#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};

void displayLinkedList(struct Node * head){
    struct Node * ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
void displayReversedLinkedList(struct Node * head){
    struct Node * ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node *));
    second = (struct Node *) malloc(sizeof(struct Node *));
    third = (struct Node *) malloc(sizeof(struct Node *));

    head->prev = NULL;
    head->data = 12;
    head->next = second;

    second->prev = head;
    second->data = 34;
    second->next = third;

    third->prev = second;
    third->data = 16;
    third->next = NULL;

    displayLinkedList(head);
    displayReversedLinkedList(head);
return 0;
}  