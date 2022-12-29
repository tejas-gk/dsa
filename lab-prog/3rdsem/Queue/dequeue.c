#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct deque
{
    int data[MAX_SIZE];
    int front, rear;
} Deque;

void init(Deque *deque)
{
    deque->front = deque->rear = MAX_SIZE / 2;
}

int is_empty(Deque *deque)
{
    return deque->front == deque->rear;
}

int is_full(Deque *deque)
{
    return deque->front == (deque->rear + 1) % MAX_SIZE;
}

void insert_front(Deque *deque, int x)
{
    if (is_full(deque))
    {
        printf("Error: Deque is full\n");
        return;
    }
    deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    deque->data[deque->front] = x;
}

void insert_rear(Deque *deque, int x)
{
    if (is_full(deque))
    {
        printf("Error: Deque is full\n");
        return;
    }
    deque->data[deque->rear] = x;
    deque->rear = (deque->rear + 1) % MAX_SIZE;
}

int delete_front(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Error: Deque is empty\n");
        return -1;
    }
    int x = deque->data[deque->front];
    deque->front = (deque->front + 1) % MAX_SIZE;
    return x;
}

int delete_rear(Deque *deque)
{
    if (is_empty(deque))
    {
        printf("Error: Deque is empty\n");
        return -1;
    }
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return deque->data[deque->rear];
}

int main()
{
    Deque deque;
    init(&deque);

    insert_front(&deque, 1);
    insert_front(&deque, 2);
    insert_rear(&deque, 3);
    insert_rear(&deque, 4);

    while (!is_empty(&deque))
    {
        printf("%d ", delete_front(&deque));
    }
    printf("\n");

    return 0;
}
