#include<iostream>
using namespace std;
#define N 100
int fib(int n){
    int dp[N];
    if(n==0)return 0;
    if(n==1)return 1;
    if(dp[n]!=0)return dp[n];
    dp[n]=fib(n-1)+fib(n-2);
    return dp[N];
}