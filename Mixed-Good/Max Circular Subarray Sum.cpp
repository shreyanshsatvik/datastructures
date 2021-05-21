class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
  
    int circularSubarraySum(int arr[], int n){
        
        // your code here
        
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+= arr[i];
        }
        
        
        int min_so_far = arr[0];
        int current_min = arr[0];
        int max_so_far = arr[0];
        int current_max = arr[0];
        for(int i=1;i<n;i++)
        {
            min_so_far = min(min_so_far+arr[i],arr[i]);
            current_min = min(current_min,min_so_far);
            max_so_far = max(max_so_far+arr[i],arr[i]);
            current_max = max(current_max,max_so_far);
        }
        
        if(current_min==sum)
        {
            return current_max;
        }
        return max(current_max,sum - current_min);
        
        
    }
};
