class Solution {
public:
 
   bool iscycle(int n,vector<bool> &visited, vector<bool>&res,vector<int> adj[])
   {
       visited[n] = true;
       res[n] = true;
       for(auto i = adj[n].begin();i!=adj[n].end();i++)
       {
          if(!visited[*i] && iscycle(*i,visited,res,adj))
          {
              return true;
          }
          if(res[*i])
          {
              return true;
          }
       }
       res[n] = false;
       return false;
   }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<bool> res(n,false);
        vector<bool> visited(n,false);
        for(int i=0;i<pre.size();i++)
        {
            int a = pre[i][0];
            int b = pre[i][1];
            adj[a].push_back(b);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(iscycle(i,visited,res,adj))
                {
                    return false;
                }
            }
            
        }
        return true;
    }
};
