int equalPartition(int n, int a[])
    {
    vector<int> arr(a,a+n);
        sort(arr.begin(),arr.end());
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0)
        {
            return 0;
        }
        else
        {
            sum = sum/2;
            vector<vector<bool>> mat(n+1,vector<bool>(sum+1));
            mat[0][0] = true;
            for(int i=1;i<n+1;i++)
            {
                mat[i][0] = false;
            }
            for(int j=1;j<sum+1;j++)
            {
                for(int i=0;i<n+1;i++)
                {
                    if(arr[i-1]>j)
                    {
                        mat[i][j] = mat[i][j-1];
                    }
                    else if(arr[i-1]<=j)
                    {
                        mat[i][j] = mat[i][j-1] || mat[i-1][j-1];
                    }
                }
            }
            if(mat[n][sum]==false)
            {
                return 0;
            }
            else
            {
                return 1;
            }
            
        }
    }
