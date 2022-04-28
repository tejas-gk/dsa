#include<iostream>
using namespace std;

int dp[100];
int fib(int n){
    if((n==0) or (n==1))return n;
    if(dp[n]==-1)return dp[n];
    dp[n]= fib(n-1)+fib(n-2);
    return dp[n];
}
int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    for(int i=0;i<=n;i++)
        cout<<fib(i)<<" ";
    
    return 0;
}
