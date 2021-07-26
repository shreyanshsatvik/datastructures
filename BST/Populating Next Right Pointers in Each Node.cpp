/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }
        
        queue<Node*> que;
        vector<Node*> arr;
        vector<vector<Node*>> ans;
        que.push(root);
        que.push(NULL);
    
        Node* temp = root;
        while(!que.empty())
        {
            Node* a = que.front();
            que.pop();
            if(a==NULL)
            {
                arr.push_back(NULL);
                ans.push_back(arr);
                arr = {};
                if(que.size()>0)
                {
                    que.push(NULL);
                }
                
            }
            else
            {
                arr.push_back(a);
                if(a->left)
                {
                    que.push(a->left);
                    
                }
                if(a->right)
                {
                    que.push(a->right);
                }
            }
            
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size()-1;j++)
            {
                ans[i][j]->next = ans[i][j+1];
            }
        }
        return temp;
    }
};
