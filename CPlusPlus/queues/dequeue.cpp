#include<iostream>
using namespace std;

class dequeue
{
    int front;
    int rear;
    int size;
    int *arr;
public:
    dequeue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void enqueueFront(int x)
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
        else if(front == 0)
        {
            front = size-1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }
    }
    void enqueueRear(int x)
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
    int dequeueFront()
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
    int dequeueRear()
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
        else if(rear == 0)
        {
            x = arr[rear];
            rear = size-1;
        }
        else
        {
            x = arr[rear];
            rear--;
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
            for(int i=front; i<=rear; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else
        {
            for(int i=front; i<size; i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0; i<=rear; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }
};
    int main(){
        dequeue q(5);
        q.enqueueFront(5);
        q.enqueueRear(10);
        q.enqueueFront(15);
        q.enqueueRear(20);
        q.enqueueFront(25);
        cout<<q.dequeueFront()<<endl;
        cout<<q.dequeueRear()<<endl;
        cout<<q.dequeueFront()<<endl;
        cout<<q.dequeueRear()<<endl;
        cout<<q.dequeueFront()<<endl;
        return 0;

    }