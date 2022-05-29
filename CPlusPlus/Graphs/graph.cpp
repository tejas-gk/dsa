#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
    void BFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
    void BFS();
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];

}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}
void Graph::DFS(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            DFSUtil(i, visited);
        }
    }
}
void Graph::BFSUtil(int v, bool visited[]){
    list<int>::iterator i;
    visited[v] = true;
    cout<<v<<" ";
    list<int> q;
    q.push_back(v);
    while(!q.empty()){
        v = q.front();
        q.pop_front();
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                cout<<*i<<" ";
                q.push_back(*i);
            }
        }
    }
}
void Graph::BFS(){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            BFSUtil(i, visited);
        }
    }
}
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<"DFS: ";
    g.DFS();
    cout<<endl;
    cout<<"BFS: ";
    g.BFS();
    cout<<endl;
    return 0;
}
