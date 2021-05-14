int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left>=right)
    {
        left = left+1;
    }
    else
    {
        right++;
    }
    return max(left,right);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
    {
        return true;
    }
    if(abs(height(root->left)-height(root->right))<=1)
    {
        return isBalanced(root->left) && isBalanced(root->right);
    }
    return false;
}
