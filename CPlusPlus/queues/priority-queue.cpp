#include<iostream>
using namespace std;

class train
{
    int front;
    int rear;
    int size;
    int *arr;
public:
    train(int s)
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
    train t(5);
    t.enqueue(1);
    t.enqueue(2);
    t.enqueue(3);
    t.enqueue(4);
    t.enqueue(5);
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.dequeue();
    t.display();
    cout<<endl;
    t.enqueue(1);
    t.display();
    cout<<endl;
    t.enqueue(2);
    t.display();
    cout<<endl;
    t.enqueue(3);
    t.display();
    cout<<endl;
    t.enqueue(4);
    t.display();
    cout<<endl;
    t.enqueue(5);
    t.display();
    cout<<endl;
    t.enqueue(6);
    t.display();
    cout<<endl;
    t.enqueue(7);
    t.display();
    cout<<endl;
    t.enqueue(8);
    t.display();
    cout<<endl;
    t.enqueue(9);
    t.display();
    cout<<endl;
    t.enqueue(10);
    t.display();
    cout<<endl;
    t.enqueue(11);
    t.display();
    cout<<endl;
    t.enqueue(12);
    t.display();
    cout<<endl;
    t.enqueue(13);
    t.display();
    cout<<endl;
    t.enqueue(14);
    t.display();
    cout<<endl;
    t.enqueue(15);
    t.display();
    cout<<endl;
    t.enqueue(16);
    t.display();
    cout<<endl;
    t.enqueue(17);
    t.display();
    cout<<endl;
    t.enqueue(18);
    t.display();
    cout<<endl;
    t.enqueue(19);
    t.display();
    cout<<endl;
    t.enqueue(20);
    t.display();
    cout<<endl;
    t.enqueue(21);
    t.display();
    cout<<endl;
    t.enqueue(22);
    t.display();
    cout<<endl;
    t.enqueue(23);
    t.display();
    cout<<endl;
    t.enqueue(24);
    t.display();
    cout<<endl;
    t.enqueue(25);
    t.display();
    cout<<endl;
    
}