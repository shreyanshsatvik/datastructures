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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
            
        vector<int> temp;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty())
        {
            TreeNode* a = que.front();
            que.pop();
            if(a==NULL)
            {
                ans.push_back(temp);
                temp = {};
                if(que.size()>0)
                {
                    que.push(NULL);
                }  
            }
            else
            {
                temp.push_back(a->val);
                if(a->left)
                {
                    que.push(a->left);
                }
                if(a->right)
                {
                    que.push(a->right);
                }
                
            }
        }
        return ans;
    }
};
