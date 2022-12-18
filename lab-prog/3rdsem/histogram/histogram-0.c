#include <stdio.h>
#include <stdlib.h>

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
    for (i = 0; i < 10; i++)
    {
        printf("[%d] ", i);
        for (j = 0; j < results[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
