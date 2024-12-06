#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->r == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void printQueue(struct queue *ptr)
{
    for (int i = ptr->f + 1; i <= ptr->r; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}
void enqueue(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue overflow\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
        if (isFull(ptr))
        {
            printf("Queue is now full!!\n");
        }
    }
}

int dequeue(struct queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
        ptr->arr[ptr->f] = 0;
        return a;
    }
}
int main()
{
    struct queue *q;
    q->size = 6;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 5);
    enqueue(q, 56);
    enqueue(q, 36);
    enqueue(q, 67);
    printQueue(q);
    printf("%d is Dequeued\n", dequeue(q));
    printf("%d is Dequeued\n", dequeue(q));
    printQueue(q);

    return 0;
}