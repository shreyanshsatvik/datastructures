class Solution{
    public:
    int rows,cols;
    vector<vector<bool>> visited;
    vector<string> ans;
    string str;
    void bfs(vector<vector<int>> &m ,int i, int j)
    {
        
        
        if(i==rows-1 && j==cols-1)
        {
            ans.push_back(str);
            return;
        }
        if(visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        if(i+1<rows && m[i+1][j]==1)
        {
            str.push_back('D');
            bfs(m,i+1,j);
            str.pop_back();
        }
        if(j-1>=0 && m[i][j-1]==1)
        {
            str.push_back('L');
            bfs(m,i,j-1);
            str.pop_back();
        }
        
        if(j+1<cols && m[i][j+1]==1)
        {
            str.push_back('R');
            bfs(m,i,j+1);
            str.pop_back();
        }
        if(i-1>=0 && m[i-1][j]==1)
        {
            str.push_back('U');
            bfs(m,i-1,j);
            str.pop_back();
        }
        
        
        visited[i][j] = false;

        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        rows = m.size();
        cols = m[0].size();
        visited = vector<vector<bool>>(rows,vector<bool>(cols,false));
        if(m[0][0] ==0)
        {
            ans.push_back("-1");
        }
        else
        {
            bfs(m,0,0);
            if(ans.size()==0)
            {
                ans.push_back("-1");
            }
        }    
        return ans;
        
    }

};
