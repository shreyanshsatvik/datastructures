vector<vector<int>> arr(n+1,vector<int> (k+1));
        for(int i=1;i<n+1;i++)
        {
            arr[i][1] = 1;
            arr[i][0] = 0;
            
        }
        // and j floors.
        for (int j = 1; j <= k; j++)
        {
            arr[1][j] = j;
        }
        for(int i=2;i<n+1;i++)
        {
            for(int j=2;j<k+1;j++)
            {
                arr[i][j] = INT_MAX;
                for(int r =1;r<=j;r++)
                {
                    int val = 1+max(arr[i-1][r-1],arr[i][j-r]);
                    if(arr[i][j]>val)
                    {
                        arr[i][j] = val;
                    }
                    
                }
            }
        }
        return arr[n][k];
    }
   
