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

struct Node * insertAtBegning(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node ));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtindex(struct Node * head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node ));
    struct Node * p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node ));
    struct Node * p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
    
}

struct Node * insertAfter(struct Node * head, struct Node * prevNode, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node ));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(2 * sizeof(struct Node *));
    second = (struct Node *) malloc(2 * sizeof(struct Node *));
    third = (struct Node *) malloc(2 * sizeof(struct Node *));

    head->data = 12;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 16;
    third->next = NULL;

    displayLinkedList(head);
    printf("\n");
    // head = insertAtBegning(head, 56);
    // head = insertAtindex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfter(head, second, 56);
    displayLinkedList(head);
    
return 0;
}