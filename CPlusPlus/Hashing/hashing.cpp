#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class hashTable{
    Node **arr;
    int size;
public:
    hashTable(int s){
        size=s;
        arr=new Node*[size];
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }
    int hash(int key){
        return key%size;
    }
    void insert(int key){
        int index=hash(key);
        Node *newNode=new Node(key);
        if(arr[index]==NULL){
            arr[index]=newNode;
        }
        else{
            Node *temp=arr[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            Node *temp=arr[i];
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    hashTable h(5);
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.print();
}
