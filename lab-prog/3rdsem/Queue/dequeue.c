#include<stdio.h>
#include<stdlib.h>

// double ended queue

int queue[100];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue()
{
    int item;
    item = queue[front];
    front++;
    return item;
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("1. Enqueue an element \t 2. Dequeue an element \t 3. Exit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            printf("Deleted element is %d", item);
            break;
        case 3:
            exit(0);
        }
    }
}
