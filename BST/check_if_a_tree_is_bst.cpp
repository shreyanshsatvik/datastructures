/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

	bool checkBST(Node* root) {
    
            return bstutil(root,0,10000);
    }
    bool bstutil(Node* root, int min ,int max)
    {
        if(root==NULL)
           {
               return true;
           }
        if(root->data>max || root->data<min)
           {
               return false;
           }
         return (bstutil(root->left,min,root->data-1)&&bstutil(root->right,root->data,max));
    }
