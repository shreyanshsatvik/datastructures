#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
void frontbacksplit(Node* source, Node** frontref,Node** backref)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
}
Node* sortedmerge(Node* a,Node* b)
{
    Node* result = NULL;
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return a;
    }
    if(a->data<=b->data)
    {
        result = a;
        a->next = sortedmerge(a->next,b);
    }
    else
    {
        result = b;
        b->next = sortedmerge(a,b->next);
    }
    return result;

}
void mergesort(Node** headref)
{
    Node* head = *headref;
    Node* a;
    Node* b;
    if(head==NULL || head->next ==NULL)
    {
        return;
    }
    frontbacksplit(head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref = sortedmerge(a,b);
}
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

int main() 
{ 
    /* Start with the empty list */
    Node* res = NULL; 
    Node* a = NULL; 
  
    /* Let us create a unsorted linked lists to test the functions  
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    /* Sort the above created Linked List */
    mergesort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
  
    return 0; 
} 

