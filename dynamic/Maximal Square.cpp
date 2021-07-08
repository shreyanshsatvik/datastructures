class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> arr(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int maxx = 0;
        for(int i=1;i<=matrix.size();i++)
        {
            for(int j=1;j<=matrix[0].size();j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    int x = min(arr[i-1][j],arr[i][j-1]);
                    arr[i][j] = min(x,arr[i-1][j-1])+1;
                    maxx = max(arr[i][j],maxx);
                }
            }
        }
        return maxx*maxx;
    }
};
