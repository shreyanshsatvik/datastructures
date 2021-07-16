

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topological(int i,vector<bool> &visited,vector<int> adj[],vector<int> &arr)
	{
	    visited[i] = true;
	    //list<int>::iterator j;
	    for(auto j=adj[i].begin();j!=adj[i].end();j++)
	    {
	        if(!visited[*j])
	        {
	            topological(*j,visited,adj,arr);
	        }
	    }
	    arr.push_back(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    
	    vector<int> arr;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            topological(i,visited,adj,arr);
	        }
	    }
	    reverse(arr.begin(),arr.end());
	    return arr;
	    
	    
	}
};


