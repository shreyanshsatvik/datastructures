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
    TreeNode* node1=NULL;
    TreeNode* node2=NULL;
    vector<TreeNode*> arr;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        bool flag = true;
        int n = arr.size()-1;
        int k = -1;
        for(int i=0;i<n;i++)
        {
            if(flag)
            {
               if(arr[i]->val>arr[i+1]->val)
                {
                    node1 = arr[i];
                    flag = false;
                    k = i;
                   
                    //n = n+1;
                } 
            }
            else
            {
                if(arr[i+1]->val<arr[i]->val)
                {
                    swap(node1->val,arr[i+1]->val);
                    flag = true;
                    break;
                }
            }
            
        }
        if(!flag)
        {
            swap(node1->val,arr[k+1]->val);
        }
        
    }
};
