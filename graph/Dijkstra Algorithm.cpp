int mindist(vector<int> dist,vector<bool> sptset,int V)
    {
        int minn = INT_MAX;
        int index;
        for(int i=0;i<V;i++)
        {
            if(!sptset[i] && dist[i]<=minn)
            {
                minn = dist[i];
                index = i;
            }
            
        }
        return index;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int> dist(V,INT_MAX);
        vector<bool> sptset(V,false);
        
        dist[S] = 0;
        
        for(int i=0;i<V-1;i++)
        {
            int u = mindist(dist,sptset,V);
            sptset[u] = true;
            
            for(int j=0;j<adj[u].size();j++)
            {
                int d = adj[u][j][0];
                int w = adj[u][j][1];
                if(!sptset[d] && w+dist[u]<dist[d]){
                    dist[d] = w+dist[u];
            }
            }
        }
    
        return dist;
        
    }
    
};
