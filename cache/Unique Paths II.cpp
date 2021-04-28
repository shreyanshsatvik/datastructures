class Solution {
public:
    
    int calculate(int m,int n,vector<vector<int>> obstacleGrid)
    {
        if(m==1 && n==1)
        {
            return 1;
        }
        if(m<=0 || n<=0 )
        {
            return 0;
        }
        else if(obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }
        return calculate(m-1,n,obstacleGrid) + calculate(m,n-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        if(m==1 && n==1)
        {
            if(obstacleGrid[0][0]==1)
            {
                return 0;
            }
        }
        int ans= calculate(m,n,obstacleGrid);
        return ans;
        
        
    }
};
