#include <stdio.h>

void printHistogram(int *a, int n);

int main()
{
    int i, j;
    int n;

    printf("Input the number of elements: \n");
    scanf("%d", &n);
    int a[n];

    printf("Input the values between 0 and 9 (separated by space): \n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    int results[10] = {0};

    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                results[i]++;
            }
        }
    }

    printf("\n");
    printHistogram(results, 10);

    return 0;
}

void printHistogram(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("[%d] ", i);
        for (j = 0; j < a[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}