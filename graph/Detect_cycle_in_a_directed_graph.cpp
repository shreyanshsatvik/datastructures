// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool iscycle(int v,vector<bool> &visited,vector<bool> &res,vector<int>adj[])
	    {
	        if(visited[v]==false)
	        {
    	        visited[v] = true;
    	        res[v] = true;
    	        //vector<int>::iterator i;
    	        for(auto i : adj[v])
    	        {
    	            if(!visited[i] && iscycle(i,visited,res,adj))
    	            {
    	                return true;
    	            }
    	            else if(res[i])
    	            {
    	                return true;
    	            }
    	        }
	        }
	        res[v]=false;
	        return false;
	    }
	bool isCyclic(int V, vector<int> adj[]) {
	    
	    vector<bool> visited(V,false);
	    vector<bool> res(V,false);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(iscycle(i,visited,res,adj))
	        {
	            return 1;
	        }
	    }
	    return 0;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	   	// code here
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
