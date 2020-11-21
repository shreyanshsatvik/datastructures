// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 


// } Driver Code Ends



/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteNode(Node* head, int k)
{
    if(k<1)
    {
        return head;
        
    }
    if(head==NULL)
    {
        return NULL;
    }
    if(k==1)
    {
        Node* rev = head->next;
        delete(head);
        return rev;
    }
    head->next = deleteNode(head->next,k-1);
    return head;
}
Node* deleteMid(Node* head)
{
    Node* new_node = head;
    Node* temp = head;
    Node* prev = NULL;
    int i =0;
    while(new_node!=NULL)
    {
        i++;
        new_node= new_node->next;
    }
    if(i%2==0)
    {
        i = i/2;
        head = deleteNode(head,i+1);
        
    }
    else
    {
        i = (i+1)/2;
        head = deleteNode(head,i);
    }
    return head;
}
