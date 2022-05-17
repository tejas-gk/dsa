#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int rotate_arr[n];
    for(int i=0;i<n;i++){
        rotate_arr[i]=arr[n-i-1];
    }
    for(int i=0;i<n;i++){
        cout<<rotate_arr[i]<<" ";
    }
    
}