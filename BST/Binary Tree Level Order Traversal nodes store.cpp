/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>rh)
        {
            lh++;
        }
        else
        {
            rh++;

        }
        return max(lh,rh);
    }
    
    void level_order(TreeNode* root,vector<int> &arr,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(level==1)
        {
            arr.push_back(root->val);
            
        }
        else if(level>1)
        {
            level_order(root->left,arr,level-1);
            level_order(root->right,arr,level-1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int hgt = height(root);
        for(int i=1;i<=hgt;i++)
        {
            vector<int> arr;
            level_order(root,arr,i);
            ans.push_back(arr);
        }
        return ans;
    }
};
