class Solution {
public:
    /*
    void addEdge(list<int> adj[],vector<vector<int>>& connections )
    {
    
        for(int i=0;i<connections.size();i++)
        {
                adj[connections[i][0]].push_back(connections[i][1]);
        }

    }
    int cal_utils(int v,list<int> adj[],vector<bool> &visited,vector<bool> &res,int data)
    {
        visited[v] = true;
        res[v] = true;
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(res[*i])
            {
                data++;
                return data;
            }
            data = cal_utils(v,adj,visited,res,data);
        }
        res[v] = false;
        return data;
    }
    int cal_cycles(list<int> adj[],int n)
    {
        vector<bool> visited(n);
        vector<bool> res(n);
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(cal_utils(i,adj,visited,res,0));
        }
        return *max_element(arr.begin(),arr.end());
    }
    */
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        
        if(n-1>connections.size())
        
        {
            return -1;
        }
        vector<int> adj[n];
        
        
        for(long long int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int> que;
        vector<bool> vis(n,false);
        int ans=0;
        vector<int>::iterator p;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                ans++;
                que.push(i);
                while(!que.empty())
                {
                    int a = que.front();
                    que.pop();
                    for(p=adj[a].begin();p!=adj[a].end();++p)
                    {
                        if(!vis[*p])
                        {
                            vis[*p] = true;
                            que.push(*p);
                        }
                    }
                }
            }
            
            
        }
        
        return ans-1;
        
                
        
        
        
        
    }
    
};
