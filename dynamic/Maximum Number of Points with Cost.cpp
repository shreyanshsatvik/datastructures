class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& points) {
        //vector<vector<long long>> arr(points.size(),vector<long long>(points[0].size()));
        int n = points.size();
        int m = points[0].size();
        if(n==1)
        {
            return *max_element(points[0].begin(),points[0].end());
        }
        long long arr[n][m];
        long long ans = -1;
        for(int i=0;i<m;i++)
        {
            arr[0][i] = points[0][i];
        }
        for(int i=1;i<n;i++)
        {
            long long left[m];
            long long right[m];
            left[0] = arr[i-1][0];
            for(int k=1;k<m;k++)
            {
                left[k] = max(left[k-1]-1,arr[i-1][k]);
            }
            right[m-1] = arr[i-1][m-1];
            for(int k=m-2;k>=0;k--)
            {
                right[k] = max(right[k+1]-1,arr[i-1][k]);
            }
            
            for(int j=0;j<m;j++)
            {
                arr[i][j] = max(left[j],right[j])+points[i][j];
                
                ans = max(ans,arr[i][j]);
    
            }
        }
        return ans;
    }
};
