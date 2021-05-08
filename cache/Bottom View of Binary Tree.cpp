// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends





//Function to return a list containing the bottom view of the given tree.

vector <int> bottomView(Node *root)
{
    
   // Your Code Here
   map<int,int> dict;
   queue<pair<int,Node*>> que;
   que.push({0,root});
   dict.insert({0,root->data});
   map<int,int>::iterator it;
   while(!que.empty())
   {
       
       int level = que.front().first;
       Node* b = que.front().second;
       que.pop();
       if(b->left!=NULL)
       {
           int l = level-1;
           it = dict.find(l);
           if(it!=dict.end())
           {
               
               it->second = b->left->data;
               //dict.erase(l);
           }
           else
           {
                dict.insert({l,b->left->data});   
           }
           
           que.push({l,b->left});
       }
       if(b->right!=NULL)
       {
           
           int l = level+1;
           it = dict.find(l);
           if(it!=dict.end())
           {
               
               it->second = b->right->data;
               //dict.erase(l);
           }
           else
           {
                dict.insert({l,b->right->data});
           }
           que.push({l,root->right});
           
       }
       
   }
  
   vector<int> arr;
   for(it = dict.begin();it!=dict.end();++it)
   {
       arr.push_back(it->second);
   }
   return arr;
   
   
}




