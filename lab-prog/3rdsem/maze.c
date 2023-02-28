#include <stdio.h>
#include <string.h>
void findpaths(int m[50][50], int row, int col, int n);
int visited[50][50], count = 0;
int main()
{
    int m[50][50], i, j, n;
    printf("Enter the size of the maze: ");
    scanf("%d", &n);
    printf("Enter the maze: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
    findpaths(m, 0, 0, n);
    printf("Total number of paths: %d", count);
    return 0;
}

void findpaths(int m[50][50], int row, int col, int n)
{
    if(row == n-1 && col == n-1)
    {
        count++;
        visited[row][col] = 1;
        printf("Path %d: ", count);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] == 1)
                    printf("(%d, %d) ", i, j);
            }
        }
        else if(row < n && col < n && m[row][col] == 1)
        {
            visited[row][col] = 1;
            findpaths(m, row+1, col, n);
            findpaths(m, row, col+1, n);
            visited[row][col] = 0;
        }
    }
    
}
