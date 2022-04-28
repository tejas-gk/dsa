#include<iostream>
#include<list>
using namespace std;
//cycle detection
#define INT_MAX 99999
class Graph
{
    int V;
    list<int> *adj;
    void dfs(int v, bool visited[])
    {
        visited[v] = true;
        for (auto i : adj[v])
        {
            if (!visited[i])
                dfs(i, visited);
            else if (visited[i] && i != v)
                cout << "Cycle detected" << endl;
        }
    }
public:

    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void detectCycle()
    {
        bool visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, visited);
    }
};
int main()
{
    return 0;
}
