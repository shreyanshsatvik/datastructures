class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        vector<int> temp;
        bfs(arr,temp,0,target,0);
        return ans;
    }
    void bfs(vector<int> &arr,vector<int> &temp,int start,int target,int sum_so_far)
    {
        if(sum_so_far==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum_so_far>target)
        {
            return;
        }
        for(int i=start;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            sum_so_far += arr[i];
            bfs(arr,temp,i,target,sum_so_far);
            sum_so_far -= arr[i];
            temp.pop_back();
        }
    }
};
