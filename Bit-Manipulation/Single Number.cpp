class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = nums[0];
        for(int j=1;j<nums.size();j++)
        {
            i ^= nums[j];
        }
        return i;
    }
};
