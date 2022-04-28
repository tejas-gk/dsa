#include<iostream>
using namespace std;
//coin change problem
#define INT_MAX 100
int dp[100];
int coinChange(int n,int *arr,int size){
    if(n==0)return 0;
    if(n<0)return -1;
    if(dp[n]!=-1)return dp[n];
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        int temp=coinChange(n-arr[i],arr,size);
        if(temp!=-1){
            if(temp+1<min)min=temp+1;
        }
    }
    if(min==INT_MAX)dp[n]=-1;
    else dp[n]=min;
    return dp[n];
}
int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    int arr[]={1,2,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<coinChange(n,arr,size);
    return 0;
}
