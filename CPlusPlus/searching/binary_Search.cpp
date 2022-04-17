#include<bits/stdc++.h>
using namespace std;
int calc(){
    
}
int main(){
    int a[10]={1,92,3,4,5,76,55,8,44,10};int n=10,key,mid;
    sort(a,a+n);
    int s=0,e=n;
    cin>>key;
    int flag=-1;
    for(int i=0;i<n;i++){
        mid=(s+e)/2;
       if(a[mid]==key){
           flag=mid;
       }else if(a[mid]>key)e=mid-1;
       else s=mid+1;
       
        
    }cout<<flag<<endl;
}