#include<iostream>
using namespace std;

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int key;
    cin>>key;
    int i=0,c=0;
    for(i=0;i<10;i++){
        if(a[i]==key){
           c++;
           cout<<"found at "<<i+1<<endl;
        }
    }
    if(c==0){
        cout<<"Not Found";
    }
    return 0;  
}