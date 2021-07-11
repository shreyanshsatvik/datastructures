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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
        {
            return NULL;
        }
        TreeNode* new_root;
        if(root1==NULL && root2)
        {
            new_root = new TreeNode(root2->val);
            new_root->left = mergeTrees(root1,root2->left);
            new_root->right = mergeTrees(root1,root2->right);
        }
        else if(root2==NULL && root1)
        {
            new_root = new TreeNode(root1->val);
            new_root->left = mergeTrees(root1->left,root2);
            new_root->right = mergeTrees(root1->right,root2);
        }
        else
        {
            new_root = new TreeNode(root1->val+root2->val);
            new_root->left = mergeTrees(root1->left,root2->left);
            new_root->right = mergeTrees(root1->right,root2->right);
        }
        return new_root;
    }
};
