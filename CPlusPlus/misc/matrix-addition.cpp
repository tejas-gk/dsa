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
    int add[row][col];
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            add[i][j]=arr[i][j]+arr0[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<add[i][j];
            if(j!=col-1)
                cout<<" ";
            else cout<<endl;
        }
    }
    
}