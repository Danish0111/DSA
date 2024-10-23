#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void printStack(struct stack *ptr)
{
    printf("Elements of stack are:\n");
    for (int j = 0; j <= ptr->top; j++)
    {
        printf("%d ", ptr->arr[j]);
    }
    printf("\n");
}
void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("stack overflow!!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int presedence(char ch){
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch =='*' || ch == '/')
    {
        return 1;
    }
    return 0;
}
char * infixToPostfix(char *infix){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char * postfix = (char * )malloc((strlen(infix)+1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (presedence(infix[i]) > presedence(s->arr[s->top]))
            {
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "a+b*c+d";
    printf("conversion of infix expression to postfix is %s", infixToPostfix(infix));
    
    return 0;
}