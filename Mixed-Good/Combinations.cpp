class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visited(n,false);
        vector<int> temp;
        bfs(1,n,k,visited,temp);
        return ans;
    }
    void bfs(int s,int n,int k,vector<bool> &visited,vector<int> &temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<=n;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                temp.push_back(i);
                bfs(i+1,n,k,visited,temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
        
};
