class Solution {
public:
    void topo_util(vector<int> &arr,vector<bool> &visited,vector<int> adj[],int i)
    {
        visited[i] = true;
        for(auto j = adj[i].begin();j!=adj[i].end();j++)
        {
            if(!visited[*j])
            {
                topo_util(arr,visited,adj,*j);
            }
        }
        arr.push_back(i);
    }
    bool detect_cycle(vector<int> adj[],vector<bool> &visited,vector<bool> &res,int i)
    {
        res[i] = true;
        visited[i] = true;
        for(auto j=adj[i].begin();j!=adj[i].end();j++)
        {
            if(res[*j]) return true;
    
            if(!visited[*j])
            {
                if(detect_cycle(adj,visited,res,*j))return true;
            }
            
        }
        res[i] = false;
        return false;
        
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited1(n,false);
        vector<bool> res(n,false);
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            if(!visited1[i])
            {
                if(detect_cycle(adj,visited1,res,i))
                {
                    return arr;
                }
            }
            
            
        }
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                topo_util(arr,visited,adj,i);
                
            }
        }
        //reverse(arr.begin(),arr.end());
        return arr;
    }
};
