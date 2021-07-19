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
    bool bst_util(TreeNode*root,long min,long max)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val<min || root->val >max)
        {
            return false;
        }
        if(root->val==INT_MAX)
        {
            if(root->right)
            {
                return false;
            }
            return bst_util(root->left,min,root->val-1);
        }
        if(root->val==INT_MIN)
        {
            if(root->left)
            {
                return false;
            }
            return bst_util(root->right,root->val+1,max);
        }
        return bst_util(root->left,min,root->val-1) && bst_util(root->right,root->val+1,max);
    }
        
    bool isValidBST(TreeNode* root) {
        return bst_util(root,INT_MIN,INT_MAX);
        
    }
};
