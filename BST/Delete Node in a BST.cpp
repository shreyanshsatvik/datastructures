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
    TreeNode* findmin(TreeNode* root){
        
        if(root->left==NULL && root->right==NULL)
        {
            return root;
        }
        if(root->left!=NULL)
        {
            return findmin(root->left);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
        {
            return root;
        }
        if(key<root->val)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(key>root->val)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                TreeNode* temp = root;
                root = NULL;
                delete temp;
                return root;
            }
            if(root->left==NULL)
            {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else if(root->right==NULL)
            {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            else
            {
                TreeNode* temp = findmin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            
                return root;
            }
        }
        return root;
        
    }
};
