class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> arr(nums.begin(),nums.end());
        arr[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            arr[i] += arr[i-1];
            //cout<<arr[i]<<" ";
        }
        
        int ans = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            ans+= mp[arr[i]-k];
            mp[arr[i]]++;
        }
        
        return ans;
    }
};
