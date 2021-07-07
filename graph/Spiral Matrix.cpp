class Solution {
public:
    vector<int> spiral(vector<vector<int>> &matrix,vector<int> arr,vector<vector<bool>> &visited,int i,int j)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        while(j<m && !visited[i][j])
        {
            visited[i][j] = true;
            arr.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
            j++;
        }
        j--;
        i++;
        while(i<n && !visited[i][j])
        {
            visited[i][j] = true;
            arr.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
            i++;
        }
        i--;
        j--;
        while(j>=0 && !visited[i][j])
        {
            visited[i][j] = true;
            arr.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
            j--;
        }
        j++;
        i--;
        while(i>=0 && !visited[i][j])
        {
            visited[i][j] = true;
            arr.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
            i--;
        }
        i++;
       
        return arr;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        bool flag = false;
        vector<int> arr;
        vector<int> ans;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j])
                {
                   arr = spiral(matrix,arr,visited,i,j);
            
                }
                
            }
        }
        
        return arr;
    }
};
