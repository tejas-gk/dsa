#include<stdio.h>
int a[20][20],q[20],visited[20],reach[20],n,i,j,f=0,r=-1,count=0;
void bfs(int v)
{
    int u;
    q[++r]=v; //enqueue the node v
    visited[v]=1;
    while(f<=r)
    {
        u=q[f++]; //dequeue u
        for(i=1;i<=n;i++)
        {
            if(a[u][i] && !visited[i])
            {
                q[++r]=i; //enqueue i
                visited[i]=1;
                printf("-->%d ",i);
            }
        }
    }
}

void dfs(int v){
    int i;
    printf("%d ",v); //print the current vertex
    reach[v]=1; //mark it as visited
    for(i=1;i<=n;i++)
        if(a[v][i] && !reach[i])
        {
            printf("-->%d ",i); //print the next vertex
            dfs(i); //call dfs for the next vertex
        }
}

void main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("Enter graph data in matrix form: ");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d",&v);
    printf("The nodes which are reachable are: ");
    bfs(v);
    printf("\n");
    for(i=1;i<=n;i++)
        reach[i]=0;
    printf("The nodes which are reachable are: ");
    dfs(v);
}
