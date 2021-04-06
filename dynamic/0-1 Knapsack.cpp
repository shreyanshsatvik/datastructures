// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<vector<int>> arr(n+1,vector<int>(W+1));
   
   for(int i =0;i<n+1;i++)
   {
       for(int k=0;k<W+1;k++)
       {
           if(i==0 || k==0)
           {
               arr[i][k] = 0;
           }
           else if(k>= wt[i-1] )
           {
               arr[i][k] = max(arr[i-1][k] , arr[i-1][k-wt[i-1]]+val[i-1]);
               
           }
           else
           {
               arr[i][k] = arr[i-1][k];
           }
       }
       
       
       
   }
   return arr[n][W];
   
   
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
