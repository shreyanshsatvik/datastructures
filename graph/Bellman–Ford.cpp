class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0] = 0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=0;j<edges.size();j++)
	        {
	            int source = edges[j][0];
	            int dest =  edges[j][1];
	            int wt = edges[j][2];
	            if(dist[source]!=INT_MAX && wt+dist[source]<dist[dest])
	            {
	                dist[dest] = dist[source]+wt;
	            }
	        
	        }
	    }
	    for(int i=0;i<edges.size();i++)
	    {
	        int source = edges[i][0];
	        int dest = edges[i][1];
	        int wt = edges[i][2];
	        if(dist[source]!=INT_MAX && dist[source]+wt<dist[dest])
	        {
	            return 1;
	        }
	    }
	    return 0;
	    
	    
	    
	    
	    
	}
};
