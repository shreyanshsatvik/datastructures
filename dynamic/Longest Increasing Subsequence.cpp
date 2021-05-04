class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> arr(n,1);
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(a[i]>a[j] && arr[i]<arr[j]+1)
               {
                   arr[i] = arr[j]+1;
               }
           }
       }
    
    return *max_element(arr.begin(),arr.end());
    }
};
