#include <stdio.h>
#include <stdlib.h>
#define size 100
void insert();
void delete();
void display();
int queue[size], front = -1, rear = -1;
void main()
{
    int ch;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}

void insert()
{
    int elem;
    if (rear == size - 1)
        printf("Queue overflow");
    else
    {
        if (front == -1)
            front = 0;
        printf("Enter the element to be inserted: ");
        scanf("%d", &elem);
        rear++;
        queue[rear] = elem;
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("The deleted element is %d", queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if (front == -1 || front > rear)
        printf("Queue is empty");
    else
    {
        printf("The elements of the queue are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
        printf("catagorization of data: \n");
        printf('less than 10');
        for (i = front; i <= rear; i++)
        {
            if (queue[i] < 10)
                printf("%d ", queue[i]);
        }
        printf('less than 20');
        for (i = front; i <= rear; i++)
        {
            if (queue[i] < 20)
                printf("%d ", queue[i]);
        }
    }
}
