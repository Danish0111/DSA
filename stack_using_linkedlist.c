#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; 
};

void displayStack(struct Node *ptr){
    printf("\n");
    
    while (ptr != NULL)
    {
        printf("|_%d_|\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int isEmpty(struct Node **ptr){
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node * push(struct Node *top, int value){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("stack overflow");
        
    }
    ptr->data = value;
    ptr->next = top;
    top = ptr;
    return top;
}

int pop(struct Node **top){
    if (isEmpty(top))
    {
        printf("Stack is Empty\n");
    }
    else{
        struct Node *ptr = *top;
        *top = (*top)->next;
        int n = ptr->data;
        free(ptr);
        return n;
    }
}
int main(){
    struct Node *top = NULL;
    top = push(top, 36);
    top = push(top, 54);
    top = push(top, 12);
    top = push(top, 64);
    // displayStack(top);
    printf("\n%d is poped", pop(&top));
    displayStack(top);
    return 0;
}