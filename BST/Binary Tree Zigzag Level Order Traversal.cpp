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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        
        que.push(root);
        que.push(NULL);
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        vector<int> arr;
        bool flag = false;
        while(!que.empty())
        {
            TreeNode* a = que.front();
            que.pop();
            if(a==NULL)
            {
                ans.push_back(arr);
                arr = {};
                if(!que.empty())
                {
                    que.push(NULL);
                }
            }
            else
            {
                arr.push_back(a->val);
               
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
        for(int i=0;i<ans.size();i++)
        {
            if(i%2!=0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        
        return ans;
    }
};
