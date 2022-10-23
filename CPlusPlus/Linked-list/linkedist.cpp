
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
class LinkedList{
public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
    void insert(int d){
        Node *newNode=new Node(d);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl; 
    }
    void sort(){
        Node *temp=head;
        while(temp!=NULL){
            Node *min_index=temp;
            while(temp->next!=NULL){
                if(temp->next->data<min_index->data){
                    min_index=temp->next;
                }
                temp=temp->next;
            }
            swap(temp->data,min_index->data);
            temp=head;
        }
    }

    int search(int key){
        Node *temp=head;
        int count=0;
        while(temp!=NULL){
            if(temp->data==key){
                return count;
            }
            count++;
            temp=temp->next;
        }
        return -1;
    }
    void deleteNode(int key){
        Node *temp=head;
        if(temp->data==key){
            head=temp->next;
            delete temp;
            return;
        }
        while(temp->next!=NULL){
            if(temp->next->data==key){
                Node *temp1=temp->next;
                temp->next=temp->next->next;
                delete temp1;
                return;
            }
            temp=temp->next;
        }
    }
    void reverse(){
        Node *prev=NULL;
        Node *curr=head;
        Node *next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void reverseRecursive(Node *curr,Node *prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        Node *next=curr->next;
        curr->next=prev;
        reverseRecursive(next,curr);
    }
    void reverseRecursive(){
        reverseRecursive(head,NULL);
    }
    
    void reverseKRecursive(Node *curr,Node *prev,int k){
        if(curr==NULL){
            head=prev;
            return;
        }
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        k--;
        if(k==0){
            head->next=curr;
            reverseKRecursive(curr,prev,k);
        }
    }
    void reverseKRecursive(int k){
        reverseKRecursive(head,NULL,k);
    }
     
};
int main(){
    LinkedList l;
    l.insert(5);
    l.insert(4);
    l.insert(3);
    l.insert(2);
    l.insert(1);
    
    l.print();
    l.reverseKRecursive(2);
    l.print();

    l.sort();
    l.search(3);
    l.print();
    l.deleteNode(3);
    l.print();
    l.reverse();
    l.print();
    l.reverseRecursive();
    l.print();

}

