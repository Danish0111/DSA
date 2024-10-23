#include <stdio.h>
#include <stdlib.h>


struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    return 0;
    
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
    
}

void printStack(struct stack *ptr){
    printf("Elements of stack are:\n");
    for (int j = 0; j <= ptr->top; j++)
    {
        printf("%d ", ptr->arr[j]);
    }
    printf("\n");
    
}
void push(struct stack *ptr){
    if(isFull(ptr)){
        printf("stack overflow!!");
    }
    else{
        int elements, value;
        printf("Enter no. of elements to insert: ");
        scanf("%d",&elements);
        

        if (elements > ptr->size)
        {
            printf("size of stack is only %d\n", ptr->size);
            scanf("%d",&elements);
        }
        if (elements > ptr->size - ptr->top-1)
        {
            printf("No enough space!! size of stack is %d and only %d space left\n", ptr->size, ptr->size - ptr->top - 1);
            scanf("%d",&elements);
        }
        
        for (int i = 1; i <= elements; i++)
        {
            printf("Enter element %d: ", i);
            scanf("%d",&value);
            ptr->top++;
            ptr->arr[ptr->top] = value;
            if (isFull(ptr))
            {
                printf("Stack is now full!!\n");
                break;
            }
        }
        printStack(ptr);
    }
}

int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack is empty");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}

int peek(struct stack *ptr){
    int i;
    printf("Enter position you wank to peek: ");
    scanf("%d",&i);
    
    if ((ptr->top - i + 1) <= 0)
    {
        printf("enter a valid position\n");
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *) malloc(s->size*sizeof(int));

    s->top++;
    s->arr[s->top] = 1;
    s->top++;
    s->arr[s->top] = 2;
    s->top++;
    s->arr[s->top] = 3;
    s->top++;
    s->arr[s->top] = 4;
    push(s);
    // printStack(s);
    // printf("%d is poped from the stack\n", pop(s));
    // printStack(s);
    // printf("element is %d", peek(s));

    return 0;
}