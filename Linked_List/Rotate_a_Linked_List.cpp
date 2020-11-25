// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k)
{
    // Your code here
    Node* new_head = head;
    k = k-1;
    while(k--)
    {
        new_head = new_head->next;
    }
    if(new_head==NULL || new_head->next==NULL)
    {
        return head;
    }
    
    Node* nnew_head = new_head->next;
    new_head->next = NULL;
    Node* head_new = nnew_head;
    while(head_new->next!=NULL)
    {
        head_new = head_new->next;
    }
    head_new->next = head;
    return nnew_head;
}
