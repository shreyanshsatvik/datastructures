class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cal = 1;
        int lptr =0;
        int rptr = 0;
        int ans = 0;
        if(k<=1)
        {
            return 0;
        }
        while(rptr<nums.size())
        {
            cal *= nums[rptr];
            while(cal>=k)
            {
                cal /= nums[lptr];
                lptr++;
            }
            ans += rptr-lptr+1;
            rptr++;
            
        }
        return ans;
    }
};
