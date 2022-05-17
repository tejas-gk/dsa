#include<iostream>
using namespace std;
int min_heapify(int a[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] < a[smallest])
    {
        smallest = l;
    }
    if (r < n && a[r] < a[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        min_heapify(a, n, smallest);
    }
}
int min_heap(int a[], int n)
{
    int i, j, temp;
    for (i = n / 2; i >= 0; i--)
    {
        min_heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        min_heapify(a, i, 0);
    }
    return a[0];
}
int main()
{
    int a[] = { 3, 2, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum element is " << min_heap(a, n);
    return 0;
}
