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
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
    {
        return 1;
    }
    return 0;
}

void printQueue(struct queue *ptr)
{
    for (int i = (ptr->f+1)%ptr->size; i != (ptr->r+1)%ptr->size;)
    {
        printf("%d ", ptr->arr[i]);
        i = (i+1)%ptr->size;
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
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = value;
        if (isFull(ptr))
        {
            printf("Queue is now full!!\n");
        }
    }
}

int dequeue(struct queue *ptr)
{
    int val = -1;
    if (isEmpty(ptr))
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        val = ptr->arr[ptr->f];
        ptr->arr[ptr->f] = 0;
        return val;
    }
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 6;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // q->r++;
    // q->arr[q->r] = 1;
    // q->r++;
    // q->arr[q->r] = 2;
    // q->r++;
    // q->arr[q->r] = 3;
    // q->r++;
    // q->arr[q->r] = 4;

    enqueue(q, 12);
    enqueue(q, 24);
    enqueue(q, 36);
    enqueue(q, 45);
    enqueue(q, 54);
    printQueue(q);

    printf("%d is Dequeued\n", dequeue(q));
    printf("%d is Dequeued\n", dequeue(q));
    printf("%d is Dequeued\n", dequeue(q));
    printf("%d is Dequeued\n", dequeue(q));
    printf("%d is Dequeued\n", dequeue(q));
    printQueue(q);

    enqueue(q, 64);
    enqueue(q, 22);
    enqueue(q, 34);
    enqueue(q, 45);
    printQueue(q);

    return 0;
}