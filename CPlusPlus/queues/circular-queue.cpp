#include<iostream>
using namespace std;

class circularQueue
{
    int front;
    int rear;
    int size;
    int *arr;
public:
    circularQueue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void enqueue(int x)
{
    if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
    {
        cout<<"Queue is full";
    }
    else if(front == -1)
    {
        front = rear = 0;
        arr[rear] = x;
    }
    else if(rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}
int dequeue()
{
    int x = -1;
    if(front == -1)
    {
        cout<<"Queue is empty";
    }
    else if(front == rear)
    {
        x = arr[front];
        front = rear = -1;
    }
    else if(front == size-1)
    {
        x = arr[front];
        front = 0;
    }
    else
    {
        x = arr[front];
        front++;
    }
    return x;
}
void display()
{
    if(front == -1)
    {
        cout<<"Queue is empty";
    }
    else if(rear >= front)
    {
        for(int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" "<<endl;
        }
    }
    else
    {
        for(int i = front; i < size; i++)
        {
            cout<<arr[i]<<" "<<endl;
        }
        for(int i = 0; i <= rear; i++)
        {
            cout<<arr[i]<<" "<<endl;
        }
    }
}
};

int main()
{
    circularQueue q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
    q.display();
    int x = q.dequeue();
    cout<<endl<<"Deleted element is "<<x<<endl;
    q.display();
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    q.display();
    return 0;
}
