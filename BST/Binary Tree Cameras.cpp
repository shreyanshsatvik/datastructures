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
            camera++;
            return 0;
        }
        if(lc==0 or rc==0)
        {
            return 1;
        }
        return -1;
    }
        
    int minCameraCover(TreeNode* root) {
        if(ans(root)==-1)
        {
            camera++;
        }
        return camera;
    }
};
