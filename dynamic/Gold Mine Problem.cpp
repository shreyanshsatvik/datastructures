
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<long long int>> arr(n,vector<long long int>(m));
        
        if(m>1 && n>1)
        {
        
        for(int i=0;i<n;i++)
        {
            arr[i][0] = M[i][0];
        }
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    arr[i][j] = max(arr[i][j-1],arr[i+1][j-1])+M[i][j];
                }
                else if(i==(n-1))
                {
                    arr[i][j] = max(arr[i][j-1],arr[i-1][j-1])+M[i][j];
                }
                else
                {
                    long long int k = max(arr[i][j-1],arr[i-1][j-1]);
                    arr[i][j] = max(arr[i+1][j-1],k) + M[i][j];
                }
            }
        }
    long long int mx =0 ;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i][m-1]>mx)
        {
            mx = arr[i][m-1];
        }
    }
    
 
    return mx;
    
    }
    
    else
    {
        if(n==1)
        {
        int k =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                k = k+ M[i][j];
            }
        }
        
        return k;
        }
        else
        {
            int max =0;
            for(int i=0;i<n;i++)
            {
                if(M[i][0]>max)
                {
                    max = M[i][0];
                }
            }
            return max;
        }
    }
    }
    
};
