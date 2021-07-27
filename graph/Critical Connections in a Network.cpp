class Solution {
public:
    void bfs(vector<int> adj[],int i,vector<int> &low,vector<int> &disc,vector<int> &parent,vector<vector<int>> &bridges)
    {
        static int time = 0;
        disc[i] = low[i] = time;
        time += 1;
        
        for(auto v=adj[i].begin();v!=adj[i].end();v++)
        {
            if(disc[*v]==-1)
            {
                parent[*v] = i;
                bfs(adj,*v,low,disc,parent,bridges);
                low[i] = min(low[i],low[*v]);
                if(low[*v]>disc[i])
                {
                    bridges.push_back({i,*v});
                }
            }
            else if(*v!=parent[i])
            {
                low[i] = min(low[i],disc[*v]);
            }
        }
        
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> low(n,-1);
        vector<int> disc(n,-1);
        vector<int> parent(n,-1);
        vector<vector<int>> bridges;
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                bfs(adj,i,low,disc,parent,bridges);
            }
        }
        return bridges;
        
        
    }
};
