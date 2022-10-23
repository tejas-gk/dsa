#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // rotate array by k
    int k;
    cin>>k;
    k=k%n;
    if(k<0){
        k=k+n;
    }
    // reverse first k elements
    int i=0;
    int j=k-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    // reverse last n-k elements
    i=k;
    

    
}