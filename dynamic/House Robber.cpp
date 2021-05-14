class Solution {
public:
 
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> arr(n,0);
        if(nums.size()>2)
        {
            arr[0] = nums[0];
            arr[1] = max(nums[1],arr[0]);
            int flag = 0;
            for(int i=2;i<n;i++)
            {
                arr[i] = max(arr[i-2]+nums[i],arr[i-1]); 
            }
            return arr[n-1];
        }
        else 
        {
            if(n==1)
            {
                return nums[0];
            }
            else
            {
                return max(nums[0],nums[1]);
            }
        }
    }
};
 

    
    
