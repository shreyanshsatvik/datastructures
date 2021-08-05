class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
       {
           int pi = partition(arr,low,high);
           quickSort(arr,low,pi-1);
           quickSort(arr,pi+1,high);
       }
       
       
        
       
    }
    
    
    int partition (int arr[], int low, int high)
    {
        
       // Your code here
        int p = arr[high];
        int l = low-1;
        for(int j=low;j<high;j++)
        {
            if(arr[j]<p)
            {
                l++;
                swap(arr[l],arr[j]);
                
            }
        }
       
    
        swap(arr[l+1],arr[high]);
        return l+1;
    
    }
};
