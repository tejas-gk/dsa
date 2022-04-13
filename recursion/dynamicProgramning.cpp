#include<iostream>
using namespace std;
//dynamic programming
#define MAX 100
int min(int a,int b){
    return a<b?a:b;
}
int minCost(int cost[][MAX],int m,int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                dp[i][j]=cost[i][j];
            }
            else{
                dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int cost[][MAX]={
        {1,2,3},
        {4,8,2},
        {1,5,3}
    };
    cout<<minCost(cost,3,3)<<endl;
}

