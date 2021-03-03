class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k;
        vector<int>arr;
        for(int i=0;i<(nums.size());i++)
        {
            if(find(nums.begin(),nums.end(),i)==nums.end())
            {
                k=i;
                arr.push_back(k);
                break;
            }
        }
        if(arr.size()==0)
        {
            k = nums.size();
        }
        return k;
        
        
    }
};
