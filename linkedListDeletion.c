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

struct Node * deleteAtBegning(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteInBetween(struct Node * head, int index){
    struct Node * ptr = head;
    int p=0;
    while (p!=index-1)
    {
        ptr = ptr->next;
    }
    struct Node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
    
}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * ptr = head;
    struct Node * q;
    while (ptr->next!=NULL)
    {
        q = ptr;
        ptr = ptr->next;
    }
    q->next = NULL;
    free(ptr);
    return head;
    
}

struct Node * deleteValue(struct Node * head, int value){
    struct Node * ptr = head;
    struct Node * q; 
    while (ptr->data!=value)
    {
        q = ptr;
        ptr = ptr->next;
    }    
    q->next = ptr->next;
    free(ptr);
    
    return head;

    
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 16;
    third->next = NULL;

    displayLinkedList(head);
    printf("\n");
    // head = deleteAtBegning(head);
    // deleteInBetween(head, 1);
    // deleteAtEnd(head);
    deleteValue(head, 34);
    displayLinkedList(head);
return 0;
}