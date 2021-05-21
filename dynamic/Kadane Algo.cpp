class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n){
        
        // Your code here
        int max_so_far = a[0];
        int curr_max = a[0];

        for(int i=1;i<n;i++)
        {
            max_so_far = max(max_so_far+a[i],a[i]);
            curr_max = max(max_so_far,curr_max);
        }
        return curr_max;
    }
};
