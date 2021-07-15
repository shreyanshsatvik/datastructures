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
 Inorder (Left, Root, Right) :  
(b) Preorder (Root, Left, Right)  
 Postorder (Left, Right, Root) :
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root_idx = 0;
        return util(preorder,inorder,root_idx,0,inorder.size()-1);
        
        
    }
    TreeNode* util(vector<int>& preorder,vector<int> &inorder,int &root_idx,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        int pivot = left;
        while(inorder[pivot]!=preorder[root_idx])
        {
            pivot++;
        }
        TreeNode* root = new TreeNode(inorder[pivot]);
        root_idx++;
        root->left = util(preorder,inorder,root_idx,left,pivot-1);
        root->right = util(preorder,inorder,root_idx,pivot+1,right);
        return root;
        
    }
};
