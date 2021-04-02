
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> arr;
      queue<Node*> que;
      que.push(node);
      while(!que.empty())
      {
          Node* a = que.front();
          arr.push_back(a->data);
          que.pop();
          if(a->left!=NULL)
          {
              que.push(a->left);
          }
          if(a->right!=NULL)
          {
              que.push(a->right);
          }
      }
      return arr;
      
      
      
    }
};
