class Solution {
public:
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int sum = (total_sum+target)/2;
       
        if(total_sum<0 || total_sum-target<0 || (total_sum+target)%2==1)
        {
            return 0;
        }
        vector<vector<int>> arr(nums.size()+1,vector<int>(sum+1,0));
        arr[0][0] =1;
        for(int i=1;i<nums.size()+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(nums[i-1]>j)
                {
                    arr[i][j] = arr[i-1][j];
                }
                else
                {
                    arr[i][j] = arr[i-1][j] + arr[i-1][j-nums[i-1]];
                }

            }
        }
        return arr[nums.size()][sum];
        
    }
    
};
