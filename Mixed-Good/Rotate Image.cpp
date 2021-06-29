class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<bool>> arr(matrix[0].size(),vector<bool>(matrix[0].size(),false));
        int n= matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!arr[i][j])
                {
                    swap(matrix[i][j],matrix[n-i-1][j]);
                    arr[i][j] = true;
                    arr[n-i-1][j] = true;
                }
            }
        }
        vector<vector<bool>> arr1(matrix[0].size(),vector<bool>(matrix[0].size(),false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!arr1[i][j])
                {
                    swap(matrix[i][j],matrix[j][i]);
                    arr1[i][j] = true;
                    arr1[j][i] = true;
                }
            }
        }
    }
};
