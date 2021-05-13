class Solution {
public:
    TreeNode* util(vector<int>& preorder,int &i,int bound)
    {
        if(i==preorder.size() || preorder[i]>bound)
        {
            return NULL;
        }
        TreeNode* new_node = new TreeNode(preorder[i++]);
        new_node->left = util(preorder,i,new_node->val);
        new_node->right = util(preorder,i,bound);
        return new_node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return util(preorder,i,INT_MAX);     
       
    }
};
