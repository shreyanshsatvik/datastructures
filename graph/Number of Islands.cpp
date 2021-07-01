class Solution {
public:
    
    bool bfs(vector<vector<bool>> &visited,vector<vector<char>>& grid,int i,int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        
        
       
        visited[i][j] = true;
        if(grid[i][j]==0)
        {

            return false;
        }
        
        
        if(i+1<m && visited[i+1][j]==false && grid[i+1][j]=='1')
        {
            if(bfs(visited,grid,i+1,j))
            {
                return true;
            }
        }
        if(i-1>=0 && visited[i-1][j]==false && grid[i-1][j]=='1')
        {
             if(bfs(visited,grid,i-1,j))
             {
                 return true;
             }
        }
        if(j+1<n && visited[i][j+1]==false && grid[i][j+1]=='1')
        {
            
            if(bfs(visited,grid,i,j+1))
            {
                return true;
            }
                
        }
        
        if(j-1>=0 && visited[i][j-1]==false&& grid[i][j-1]=='1')
        {
            
            if(bfs(visited,grid,i,j-1))
            {
                return true;
            }
        }
        return false;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              
                if(visited[i][j]==false && grid[i][j]=='1')
                {
                    
                    count++;
                    if(bfs(visited,grid,i,j)==false)
                    {
                        continue;
                    }
                    
                    
                    
                }
                
                
            }
        }
        return count;
    }
};
