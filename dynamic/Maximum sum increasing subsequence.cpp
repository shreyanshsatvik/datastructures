class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> lis(arr,arr+n);
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j] && lis[i]<lis[j]+arr[i])
	            {
	                lis[i] = lis[j]+arr[i] ;
	                
	                
	            }
	        }
	    }
	    
	    return *max_element(lis.begin(),lis.end());
	}  
};
