class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        vector<int> temp;
        backtrack(nums,temp,visited);
        return ans;
        
    }
    void backtrack(vector<int>&nums, vector<int> &temp,vector<bool> &visited)
    {
        if(nums.size()==temp.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                temp.push_back(nums[i]);
                backtrack(nums,temp,visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
        
    }
};
