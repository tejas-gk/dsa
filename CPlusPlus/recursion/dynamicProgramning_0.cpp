#include<iostream>
using namespace std;
//why tf is this shit not working
//fibonacci using dynamic programming
int fib(int n)
{
    int *f = new int[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main(){
    int n;
    cin >> n;
    for(int i=n;i>n;i--)
    {
       
        cout << fib(n) << endl;
    }

    return 0;
}
   