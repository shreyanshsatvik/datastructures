public:
    int rows,cols;
    vector<bool> visited;
    vector<string> ans;
    queue<int> que;
    string str;
    void bfs(vector<vector<int>> &m ,int i, int j)
    {
        rows = m.size();
        cols = m[0].size();
        
        if(i==rows-1 && j==cols-1)
        {
            ans.push_back(str);
            return;
        }
        
        if(i-1>=0 && m[i-1][j]==1)
        {
            str.push_back("D");
            bfs(m,i-1,j);
            str.pop_back();
        }
        if(i+1<rows && m[i+1][j]==1)
        {
            str.push_back("U");
            bfs(m.i+1,j);
            str.pop_back();
        }
        if(j-1>=0 && m[i][j-1]==1)
        {
            str.push_back("L");
            bfs(m,i,j-1);
            str.pop_back();
        }
        if(j+1>cols && m[i][j+1]==1)
        {
            str.push_back("R");
            bfs(m,i,j+1);
            str.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        bfs(m,0,0);
        return ans;
