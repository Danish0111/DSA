#include <stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue * ptr){
    if (ptr->r == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue * ptr){
    if (ptr->r == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void printQueue(struct queue * ptr){
    for (int i = 0; i <= ptr->r; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
    
}
void enqueue(struct queue *ptr){
    if (isFull(ptr))
    {
        printf("Queue overflow\n");
    }
    else{
        int elements, value;
        printf("Enter no. of elements to insert: ");
        scanf("%d",&elements);
        

        if (elements > ptr->size)
        {
            printf("size of Queue is only %d\n", ptr->size);
            scanf("%d",&elements);
        }
        if (elements > ptr->size - ptr->r-1)
        {
            printf("No enough space!! size of Queue is %d and only %d space left\n", ptr->size, ptr->size - ptr->r - 1);
            scanf("%d",&elements);
        }
        
        for (int i = 1; i <= elements; i++)
        {
            printf("Enter element %d: ", i);
            scanf("%d",&value);
            ptr->r++;
            ptr->arr[ptr->r] = value;
            if (isFull(ptr))
            {
                printf("Queue is now full!!\n");
                break;
            }
        }
    }
    printQueue(ptr);
}

int dequeue(struct queue * ptr){
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("Queue is empty!!\n");
    }
    else{
        ptr->f++;
        a = ptr->arr[ptr->f];
        ptr->arr[ptr->f] = 0;
        return a;
    }
}
int main(){
    struct queue *q;
    q->size = 6;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    q->r++;
    q->arr[q->r] = 1;
    q->r++;
    q->arr[q->r] = 2;
    q->r++;
    q->arr[q->r] = 3;
    q->r++;
    q->arr[q->r] = 4;
    
    // enqueue(q);
    printf("%d is Dequeued\n", dequeue(q));
    printQueue(q);
    
    return 0;
}