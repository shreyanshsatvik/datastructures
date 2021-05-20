class Solution 
{
    
    public:
	vector<int> arr;
	//vector<bool> visited(false);

	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int i,vector<int> adj[],vector<bool> &visited)
	{
	    
	    arr.push_back(i);
	    visited[i] = true;
	    vector<int> :: iterator it;
	    for(it=adj[i].begin();it!=adj[i].end();++it)
	    {
	        if(!visited[*it])
	        {
	            dfs(*it,adj,visited);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool> visited(V,false);
	   
	    dfs(0,adj,visited);
	    
	    return arr;
	}
};
