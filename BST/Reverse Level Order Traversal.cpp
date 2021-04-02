vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> arr;
    queue<Node*> que;
    que.push(root);
    while(!que.empty())
    {
        Node* a = que.front();
        arr.push_back(a->data);
        que.pop();
        if(a->right!=NULL)
        {
            que.push(a->right);
        }
        if(a->left!=NULL)
        {
            que.push(a->left);
        }
        
        
    }
    reverse(arr.begin(),arr.end());
    return arr;
}
