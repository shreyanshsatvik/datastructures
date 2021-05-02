class Solution
{
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> wt;
        
        wt.push_back(x);
        wt.push_back(y);
        wt.push_back(z);
    
        vector<vector<int>> arr(4,vector<int>(n+1));
        for(int i=0;i<4;i++)
        {
            arr[i][0] = 0;
        }
        for(int j=0;j<n+1;j++)
        {
            arr[0][j] = INT_MIN;
        }
        arr[0][0] =0;
        for(int i=1;i<4;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(j>=wt[i-1])
                {
                    arr[i][j] = max(arr[i-1][j],1+arr[i][j-wt[i-1]]);
                }
                else
                {
                    arr[i][j] = arr[i-1][j];
                }
            }
        }
        if(arr[3][n]<0)
        {
            return 0;
        }
        return arr[3][n];
        
        
        
        
        
    }
};
