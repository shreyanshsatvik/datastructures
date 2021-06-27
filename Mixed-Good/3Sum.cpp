class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
        {
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
                int a = -1*nums[i];
                int front = i+1;
                int back = nums.size()-1;
                while(front<back)
                {
                    int sum = nums[front] + nums[back];
                    if(a>sum)
                    {
                        front++;
                    }
                    else if(a<sum)
                    {
                        back--;
                    }
                    else
                    {
                        vector<int>arr;
                        arr = {nums[i],nums[front],nums[back]};
                        if(find(ans.begin(),ans.end(),arr)==ans.end())
                        {
                            ans.push_back(arr);
                        
                        }
                        while (front < back && nums[front] == nums[front+1]) front++;
                        while (front < back && nums[back] == nums[back-1]) back--;
                        front++;
                        back--;
                    }
                }
                 
        }
        return ans;
    }
};
