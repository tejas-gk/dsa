#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int count;
typedef struct node *node;
node head = NULL;

node create()
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->next = NULL;
    return temp;
}

node insertFront(node head, int item)
{
    node temp;
    temp = create();
    temp->data = item;
    temp->next = head;
    head = temp;
    count++;
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
    }
    count++;
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
        printf("Deleted element is %d", temp->data);
        free(temp);
        count--;
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
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        printf("Deleted element is %d", temp->data);
        free(temp);
        count--;
    }
    else
    {
        p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        printf("Deleted element is %d", temp->data);
        free(temp);
        count--;
    }
    return head;
}

void display()
{
    node temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch, item;
    while (1)
    {
        printf(" 1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.Exit");
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
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
