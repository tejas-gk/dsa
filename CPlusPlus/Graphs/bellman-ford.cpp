#include<iostream>
#include<list>
using namespace std;
#define INT_MAX 99999
//bellman ford
class Graph
{
    int V;
    list<int> *adj;
    void bellmanFord(int s, int dist[], bool sptSet[])
    {
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }
        dist[s] = 0;
        for (int count = 0; count < V - 1; count++)
        {
            for (int u = 0; u < V; u++)
            {
                for (auto v : adj[u])
                {
                    if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + 1 < dist[v])
                        dist[v] = dist[u] + 1;
                }
            }
        }
    }
    int minDistance(int dist[], bool sptSet[])
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }
};
int main()
{
    return 0;
}
