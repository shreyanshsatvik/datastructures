// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int a=0;
    int b=0;
    Node* new_head1 = head1;
    Node* new_head2 = head2;
    while(new_head1!=NULL)
    {
        a++;
        new_head1 = new_head1->next;
    }
    while(new_head2!=NULL)
    {
        b++;
        new_head2 = new_head2->next;
    }
    int c = abs(a-b);
    if(a>b)
    {
        while(c--)
        {
            if(head1==NULL)
            {
                return -1;
            }
            head1 =head1->next;
        }
        while(head1!=NULL && head2!=NULL)
        {
            if(head1==head2 )
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    }
    else if(b>a)
    {
        while(c--)
        {
            if(head2==NULL)
            {
                return -1;
            }
            head2 =head2->next;
        }
        while(head2!=NULL && head1!=NULL)
        {
            if(head1==head2 )
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    }
    if(a==b)
    {
    
        while(head1!=NULL && head2!=NULL)
        {
            if(head1==head2 )
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    int d = abs(a-c);
    while(d--)
    {
        head1 = head1->next;
    }
    int e = abs(c-b);
    while(e--)
    {
        head2 = head2->next;
    }
    while(head1!=NULL || head2!=NULL)
    {
        if(head1->data==head2->data)
        {
            return head1->data;
            break;
        }
        else
        {
            
        }
    }
    */
}

