#include <stdio.h>
#include <string.h>
void findpaths(int m[50][50], int row, int col, int n);
int visited[50][50], count = 0;
int main()
{
    int m[50][50], i, j, n, row, col;
    printf("Enter the size of the maze: ");
    scanf("%d", &n);
    printf("Enter the maze: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
    printf("enter the entrance (row and col) ");
    scanf("%d %d", &row, &col);
    if (m[row][col] == 0)
    {
        printf("No path exists");
        return 0;
    }
    findpaths(m, row, col, n);
    if (count == 0)
        printf("No path exists");
    else
        printf("Total number of paths: %d", count);
    return 0;
}

// This is a recursive function which is used to find all the possible paths
// from the source (0,0) to the destination (n-1, n-1) in the matrix.
// m is the input matrix which contains 0 and 1. 0 means the path is blocked and 1 means the path is not blocked.
// row and col are the current position in the matrix.
// n is the size of the matrix.
// visited is a global variable which is used to keep track of the visited nodes in the matrix.
// count is a global variable which is used to keep track of the number of paths found.
void findpaths(int m[50][50], int row, int col, int n)
{
    // If the current position is the destination then print the path.
    if (row == n - 1 && col == n - 1)
    {
        count++;
        visited[row][col] = 1;
        printf("Path %d: ", count);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", visited[i][j]);
            }
            printf("\n");
        }
            visited[row][col] = 0;
            return;
    }
    // If the current position is not the destination then mark the current position as visited.
    else
    {
        visited[row][col] = 1;
    }

    // If the position below the current position is not blocked, is not yet visited and is within the matrix then call the function recursively with the position below the current position as the current position.
    if(row+1<n && m[row+1][col]==1 && visited[row+1][col]==0)
        findpaths(m, row+1, col, n);
    // If the position to the right of the current position is not blocked, is not yet visited and is within the matrix then call the function recursively with the position to the right of the current position as the current position.
    if(col+1<n && m[row][col+1]==1 && visited[row][col+1]==0)
        findpaths(m, row, col+1, n);
    // If the position above the current position is not blocked, is not yet visited and is within the matrix then call the function recursively with the position above the current position as the current position.
    if(row-1>=0 && m[row-1][col]==1 && visited[row-1][col]==0)
        findpaths(m, row-1, col, n);
    // If the position to the left of the current position is not blocked, is not yet visited and is within the matrix then call the function recursively with the position to the left of the current position as the current position.
    if(col-1>=0 && m[row][col-1]==1 && visited[row][col-1]==0)
        findpaths(m, row, col-1, n);
    // If the current position is not the destination then mark the current position as not visited.
    visited[row][col] = 0;
    
}
