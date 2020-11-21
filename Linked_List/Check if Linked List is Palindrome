// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
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
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    vector<int> arr;
    while(head!=NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }
    vector<int> reverse = arr;
    std::reverse(arr.begin(), arr.end());
    if(reverse==arr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    /*
    
    if(arr.size()%2==0)
    {
        int mid = arr.size()/2;
        vector<int> start(arr.begin(),arr.begin()+mid);
        vector<int> end(arr.begin()+mid,arr.end());
        if(start==end)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        int mid = (arr.size()-1)/2;
        vector<int> start(arr.begin(),arr.begin()+mid);
        vector<int> end(arr.begin()+mid+1,arr.end());
        if(start==end)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    */
}

