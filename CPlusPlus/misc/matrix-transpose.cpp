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
    cout<<"the tranpose is"<<endl;
    int transpose[row][col];
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            transpose[j][i]=arr[i][j];
        }
    }

    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<transpose[i][j];
            cout<<" ";
            if(j==row-1)
                cout<<endl;
            
        }
    }

}