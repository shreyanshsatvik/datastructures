class Solution {
public:
    bool cycle(int v,int s,vector<bool> visited,vector<int> adj[])
    {
        visited[v] = true;
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                if(cycle(i,v,visited,adj))
                {
                    return true;
                }
            }
            else if(visited[i] && i!=s)
            {
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> visited(V,false);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	        
	        if(cycle(i,-1,visited,adj))
	        {
	            return 1;
	        }
	        }
	    }
	    return 0;
