class Solution {
public:
   
    int maximumUniqueSubarray(vector<int>& nums) {
        int lptr = 0;
        int rptr = 1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int> arr(100001,-1);
        int maxx_sum = 0;
        arr[nums[0]] = 0;
        vector<int> ss(199992,0);
        
        ss[0] = 0;
        ss[lptr+1] = nums[0];
        
        while(rptr>lptr && rptr<nums.size())
        {
            if(arr[nums[rptr]]!=-1)
            {
                lptr = max(lptr,arr[nums[rptr]]+1);
            }
            arr[nums[rptr]] = rptr;
            ss[rptr+1] = nums[rptr]+ss[rptr]; 
            int sum = ss[rptr+1]-ss[lptr];
            maxx_sum = max(maxx_sum,sum);
            rptr++;
            
        }
        return maxx_sum;
    }
};
