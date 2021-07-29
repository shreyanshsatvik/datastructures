class Solution {
public:
    
    int mindist(vector<bool> visited,vector<long long int> dist,int n)
    {
        int minn = 99999;
        int index;
    
        for(int i=0;i<=n;i++)
        {
            if(!visited[i] && dist[i]<=minn)
            {
                minn = dist[i];
                index = i;
            } 
        }
        return index;
        
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        bool flag = false;
        
        vector<bool> visited(n+1,false);
        vector<long long int> dist(n+1,99999);
        vector<pair<int,int>> g[n+1];
        for(int i=0;i<times.size();i++)
        {
            g[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));   
        }
            
        dist[k] = 0;
        for(int i=1;i<=n;i++)
        {
            int u = mindist(visited,dist,n);
            visited[u] = true;
            for(int it = 0;it<g[u].size();it++)
            {
                
                int v = g[u][it].first;
                int w = g[u][it].second;
                
                
                if(!visited[v] && dist[u]+w<dist[v])
                {
                    dist[v] = dist[u]+w;
                }
            }
            
        }
        if(*max_element(dist.begin()+1,dist.end())==99999)
           {
               return -1;
           }
        return *max_element(dist.begin()+1,dist.end());
        
        
        
        
    }
};
