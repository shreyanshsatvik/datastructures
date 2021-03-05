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
        int ltree = height(root->left);
        int rtree = height(root->right);
        if(ltree>rtree)
        {
            ltree++;
        }
        else if(ltree<=rtree)
        {
            rtree++;
        }
        return max(ltree,rtree);
        
    }
    void levelorder(TreeNode* root,int level,vector<int> &arr)
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
            levelorder(root->left,level-1,arr);
            levelorder(root->right,level-1,arr);
        }
    }
    
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> arr;
        int h = height(root);
        for(int i=1;i<=h;i++)
        {
            vector<int> ar;
            levelorder(root,i,ar);
            double k=0;
            for(int j=0;j<ar.size();j++)
            {
                k = k+ ar[j];
            
            }
            k = k/ar.size();
            arr.push_back(k);

        }
        return arr;
    }
};
