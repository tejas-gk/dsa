#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};

typedef struct node *node;

node head = NULL;


node create()
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

node insertFront(node head, int item)
{
    node temp;
    temp = create();
    temp->data = item;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

node insertRear(node head, int item)
{
    node temp, p;
    temp = create();
    temp->data = item;
    p = head;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    return head;
}

node deleteFront(node head)
{
    node temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    return head;
}

node deleteRear(node head)
{
    node temp, p;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        temp = p;
        p->prev->next = NULL;
        free(temp);
    }
    return head;
}

void display(node head)
{
    node p;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        p = head;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

int main()
{
    int ch, item;
    while (1)
    {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            head = insertFront(head, item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            head = insertRear(head, item);
            break;
        case 3:
            head = deleteFront(head);
            break;
        case 4:
            head = deleteRear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
