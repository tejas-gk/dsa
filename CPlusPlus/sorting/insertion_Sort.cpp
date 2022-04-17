#include<iostream>
using namespace std;

int insertSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)cin>>arr[i];

    insertSort(arr, n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}