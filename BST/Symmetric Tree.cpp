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
    bool Symmetry(TreeNode* left_node,TreeNode* right_node)
    {
        if(left_node==NULL && right_node==NULL)
        {
            return true;
        }
        else if(!left_node && right_node)
        {
            return false;
        }
        else if(!right_node && left_node)
        {
            return false;
        }
        if(left_node->val == right_node->val)
        {
            
            return Symmetry(left_node->left,right_node->right) && Symmetry(left_node->right,right_node->left);
        }
        
        return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)
        {
            return true;
        }
        
        TreeNode* left_root = root->left;
        TreeNode* right_root = root->right;
        
        return Symmetry(left_root,right_root);
       
    }
};
