
void levelorder(Node* root,int level,vector<int> &arr)
{
    if(root==NULL)
    {
        return;
    }
    if(level==1)
    {
        arr.push_back(root->data);
    }
    else if(level>1)
    {
        levelorder(root->left,level-1,arr);
        levelorder(root->right,level-1,arr);
    }
}
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>=rh)
    {
        lh++;
        return lh;
    }
    else
    {
        rh++;
        return rh;
    }
    return max(lh,rh);
}
vector<int> leftView(Node *root)
{
   // Your code here
  int h = height(root);
  vector<int> ans;
  for(int i=1;i<=h;i++)
  {
      vector<int> arr;
      levelorder(root,i,arr);
      ans.push_back(arr[0]);
  }
    
  return ans;
   
}
