#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->length = 0;
    queue->capacity = capacity;
    queue->storage = malloc(sizeof(int) * capacity);
    return queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    // making space for item if storage capacity is reached
    if (q->length >= q->capacity)
    {
        q->storage = resize_memory(q->storage, q->capacity, q->capacity + 1);
    }
    // appending item to end of array and incrementing length
    q->storage[q->length] = item;
    q->length++;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    // returning -1 if queue is empty
    if (q->length == 0)
        return -1;
    unsigned int i;
    // storing removed item to return later
    int removed_item = q->storage[0];
    // looping through q->storage to shift items to left
    for (i = 0; i < q->length - 1; i++)
    {
        q->storage[i] = q->storage[i+1];
    }
    // decrementing length
    q->length--;
    return removed_item;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    free(q->storage);
    free(q);
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif