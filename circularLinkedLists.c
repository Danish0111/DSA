#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};

void displayLinkedLists(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    printf("\n");
    
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 34;
    head->next =  second;

    second->data = 4;
    second->next = third;

    third->data = 14;
    third->next = head;

    displayLinkedLists(head);
    head = insertAtFirst(head, 56);
    displayLinkedLists(head);
return 0;
}