class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0)
        {
            return NULL;
        }
        if(n%2==0)
        {
            n = n/2 - 1;
        }
        else
        {
            n = n/2;
        }
        TreeNode* root = new TreeNode(nums[n]);
        vector<int> arr1(nums.begin(),nums.begin()+n);
        vector<int> arr2(nums.begin()+n+1,nums.end());
        root->right = sortedArrayToBST(arr2);
        root->left = sortedArrayToBST(arr1);
        return root;
    }
};
