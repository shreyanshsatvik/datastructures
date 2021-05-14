class Solution {
public:
    vector<int> arr;
    void preorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        arr.push_back(root->val);
        preorder(root->left);
        
        preorder(root->right);
        
    }
    void flatten(TreeNode* root) {
        //vector<int> arr;
        
        //sort(arr.begin(),arr.end());
        TreeNode* original_root= root;
        preorder(root);
        if(arr.size()>0)
        {
            original_root->val = arr[0];
            original_root->left = NULL;
            if(arr.size()>1)
            {
                for(int i=1;i<arr.size();i++)
                {
                    TreeNode* new_node = new TreeNode(arr[i]);
                    original_root->right = new_node;
                    original_root = original_root->right;

                }
            }
        }
        
        //root = root->right->right;

        
        
        
    }
};
