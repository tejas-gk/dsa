#include<iostream>
using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    int arr[row][col];
    int arr0[row][col];
    cout<<"enter matrix A"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"enter matrix B"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr0[i][j];
        }
    }
    int k;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            k=0;
            for(int l=0;l<row;l++){
                k=k+arr[i][l]*arr0[l][j];
            }
            cout<<k<<" ";
        }
        cout<<endl;
    }
}