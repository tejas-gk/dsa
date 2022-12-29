#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data;
    int priority;
} Element;

typedef struct
{
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void init(PriorityQueue *queue)
{
    queue->size = 0;
}

int is_empty(PriorityQueue *queue)
{
    return queue->size == 0;
}

int is_full(PriorityQueue *queue)
{
    return queue->size == MAX_SIZE;
}

void insert(PriorityQueue *queue, int data, int priority)
{
    if (is_full(queue))
    {
        printf("Error: Queue is full\n");
        return;
    }

    Element element;
    element.data = data;
    element.priority = priority;

    int i;
    for (i = queue->size - 1; i >= 0; i--)
    {
        if (queue->elements[i].priority < priority)
        {
            queue->elements[i + 1] = queue->elements[i];
        }
        else
        {
            break;
        }
    }
    queue->elements[i + 1] = element;
    queue->size++;
}

int dequeue(PriorityQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->elements[queue->size - 1].data;
    queue->size--;
    return data;
}

int main()
{
    PriorityQueue queue;
    init(&queue);

    insert(&queue, 1, 2);
    insert(&queue, 2, 1);
    insert(&queue, 3, 3);
    insert(&queue, 4, 0);

    while (!is_empty(&queue))
    {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
