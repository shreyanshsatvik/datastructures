class Solution {
public:
    /*
    -1 - camera has no view
    0 - camera's location
    1 - camera has view
    */
    int camera = 0;
    int ans(TreeNode* root)
    {
        if(!root)
        {
            return 1;
        }
        int lc = ans(root->left);
        int rc = ans(root->right);
        if(lc==-1 or rc==-1)
        {
            root->val = 0;
            camera++;
            return root->val;
        }
        if(lc==0 or rc==0)
        {
            root->val = 1;
            return root->val;
        }
        root->val = -1;
        return root->val;
    }
        
    int minCameraCover(TreeNode* root) {
        if(ans(root)==-1)
        {
            camera++;
        }
        return camera;
    }
};
