bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> adj[V+1];
    for (int i = 0; i <V; i++)
      {
         for(int j =0;j<V;j++)
         {
             if(graph[i][j])
             {
                  adj[i].push_back(j);
              }
         }
      }
    
    vector<bool> visited(V,false);
    queue<int> que;
    int max_color = 1;

    vector<int> color(V,1);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            que.push(i);
            visited[i] = true;
            while(!que.empty())
            {
                int s = que.front();
                que.pop();
                for(auto it=adj[s].begin();it!=adj[s].end();it++)
                {
                    if(color[*it]==color[s])
                    {
                        color[*it] += 1;
                    }
                    
                    max_color = max(max_color,max(color[s],color[*it]));
                    if(max_color>m)
                    {
                        return false;
                    }
                    
                    if(!visited[*it])
                    {
                        visited[*it] = true;
                        que.push(*it);
                    }
                }
                
            }
        }
        
    }
    
    
    return true;
}
