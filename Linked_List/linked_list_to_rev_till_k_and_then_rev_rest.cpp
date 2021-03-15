// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *rev(struct node* head,int k)
    {
        if(k==1 )
        {
            //head->next = NULL;
            //struct node* r_n = head->next;
            return head;
        }
        struct node* r = rev(head->next,k-1);
        head->next->next = head;
        head->next = NULL;
        return r;
        
        
        
    }
    
    struct node* re(struct node * head, int k)
    {
        struct node* new_head = head;
        while(k-- )
        {
            new_head = new_head->next;
           
        }
        return new_head;
    }
    struct node* reve(struct node* head)
    {
        if(head->next==NULL or head==NULL)
        {
            return head;
        }
        struct node* rev = reve(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node* new_head = re(head,k);
        struct node* nn_head = rev(head,k);
        
        /*
        while(c_head->next!=NULL)
        {
            c_head = c_head->next;
        }
        c_head->next = new_head;
    
        */
        if(new_head == NULL)
        {
            return nn_head;
        }
        else
        {
            struct node* c_head =  reve(new_head);
            head->next = c_head;
        }
        return nn_head;
        
    
        
        
        
        
        
        
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends
