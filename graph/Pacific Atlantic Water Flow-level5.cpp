class Solution {
public:
    int m,n;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<int>> ans;
    queue<pair<int,int>> que;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
        m = heights.size();
        n = heights[0].size();
        pacific = atlantic = vector<vector<bool>> (m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            bfs(heights,pacific,i,0);
            bfs(heights,atlantic,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            bfs(heights,pacific,0,i);
            bfs(heights,atlantic,m-1,i);
        }
        
    return ans;
        
        
        
    }
 
    void bfs(vector<vector<int>>& heights, vector<vector<bool>> &visited,int i,int j)
    {
        que.push({i,j});
        
        
        while(!que.empty())
        {
            tie(i,j) = que.front();
            que.pop();
            if(!visited[i][j])
            {
                visited[i][j] = true;
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back(vector<int>{i,j});

                }
            
                if(i-1>=0 && heights[i-1][j]>=heights[i][j])
                {
                    que.push({i-1,j});
                }
                if(i+1< m && heights[i+1][j]>=heights[i][j])
                {
                    que.push({i+1,j});
                }
                if(j-1>=0 && heights[i][j-1]>=heights[i][j])
                {
                    que.push({i,j-1});
                }
                if(j+1< n && heights[i][j+1]>=heights[i][j])
                {
                    que.push({i,j+1});
                }
            }
            
        }
        
        
        
        
    }
    
    
    
    
    
    
};
