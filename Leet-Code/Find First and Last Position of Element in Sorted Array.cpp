class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr(2,-1);
        vector<int>::iterator it;
        int s = nums.size();
        it = find(nums.begin(),nums.end(),target);
        if(it!=nums.end())
        {
            arr[0] = (it-nums.begin());
        }
        reverse(nums.begin(),nums.end());
        it = find(nums.begin(),nums.end(),target);
        if(it!=nums.end())
        {
            if(s-arr[0]!=it-nums.begin())
            {
                arr[1] =it-nums.begin();
                arr[1] = s-arr[1]-1;
            }
        }
    
        return arr;
    }
};
