int count_element(Node* root)
{
    int count = 0;
    vector<int> arr;
    queue<Node*> que;
    que.push(root);
    while(!que.empty())
    {
        Node* a = que.front();
        que.pop();
        arr.push_back(a->data);
        if(a->left)
        {
            que.push(a->left);
        }
        if(a->right)
        {
            que.push(a->right);
        }
    }
    return arr.size();
}

bool checkBST(Node* root,int min , int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>max || root->data<min)
    {
        return false;
    }
    return checkBST(root->left,min,root->data-1) && checkBST(root->right,root->data+1,max);
}
int largestBst(Node *root)
{
	//Your code here
	int max_height = 1;
	queue<Node*> que;
	que.push(root);
	while(!que.empty())
	{
	    Node* a = que.front();
	    que.pop();
	    if(checkBST(a,INT_MIN,INT_MAX))
	    {
	        max_height = max(max_height,count_element(a));
	    }
	    if(a->left)
	    {
	        que.push(a->left);
	    }
	    if(a->right)
	    {
	        que.push(a->right);
	    }
	}
	return max_height;
}
