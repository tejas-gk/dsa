#include<iostream>
using std::cout;
using std::endl;
using std::swap;

auto max_heapify(int a[], int n, int i) -> void
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        max_heapify(a, n, largest);
    }
}

int max_heap(int a[], int n)
{
    int i, j, temp;
    for (i = n / 2; i >= 0; i--)
    {
        max_heapify(a, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        max_heapify(a, i, 0);
    }
    return a[0];
}

int main()
{
    int a[] = { 3, 2, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum element is " << max_heap(a, n);
    return 0;
}
