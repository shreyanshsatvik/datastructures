class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr;
        for (int i=0;i<nums.size();i++)
        {
            if(count(nums.begin(),nums.end(),nums[i])==2)
            {
                arr.push_back(nums[i]);
                break;
            }
            
        }
        
        int l=1;
        for(int i =0;i<nums.size();i++)
        {
            if(find(nums.begin(),nums.end(),l)!=nums.end())
            {
                l++;      
            }
            else
            {
                arr.push_back(l);
                break;
            }
        }
        if(arr.size()!=2)
        {
            arr.push_back(nums.size());
        }
        return arr;
    }
};
