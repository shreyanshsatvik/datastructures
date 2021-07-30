class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        int c = 1;
        int l = sqrt(n);
        if(l*l==n)
        {
            return 1;
        }
        while(pow(c,2)<n)
        {
            nums.push_back(c*c);
            c++;
            
        }
        vector<vector<int>> arr(nums.size()+1,vector<int>(n+1));
        for(int i=0;i<nums.size();i++)
        {
            arr[i][0] = INT_MAX;
        }
        for(int i=0;i<n+1;i++)
        {
            arr[0][i] = 0;
        }
        for(int i=1;i<nums.size()+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                
                if(j>=nums[i-1])
                {
                    if(j%nums[i-1]==0)
                    {
                        arr[i][j] = j/nums[i-1];
                    }
                    else
                    {
                        arr[i][j] = min(arr[i-1][j],arr[i][j-nums[i-1]]+1);
                    }
                    
                    
                }
                else
                {
                    arr[i][j] = arr[i-1][j];
                }
                
            }
            
        }
        return arr[nums.size()][n];
    }
};

