#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;


public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);

};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
void Graph::BFS(int s)
{
    vector<bool> visited(V,false);
    queue<int> que;
    visited[s] = true;
    que.push(s);
    list<int>::iterator i;
    while(!que.empty())
    {
        s = que.front();
        cout<<s<<" ";
        que.pop();
        for(i = adj[s].begin();i!=adj[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                que.push(*i);

            }
        }
    }
    



}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
}
