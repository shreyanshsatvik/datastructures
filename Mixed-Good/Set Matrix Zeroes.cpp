class Solution {
public:
    void zero(vector<vector<int>> &matrix,int row,int col,vector<vector<bool>> &visited)
    {
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i=0;i<m;i++)
        {
            if(matrix[i][col]==0)
            {
                continue;
            }
            matrix[i][col] =0;
            visited[i][col] = true;
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[row][i]==0)
            {
                continue;
            }
            matrix[row][i] = 0;
            visited[row][i] = true;
        }
    }
        
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(matrix[i][j]==0 && !visited[i][j])
                {
                    
                    zero(matrix,i,j,visited);
                
                }
                
                
            }
        }
        
        
    }
};
