public:
    /*
    bool part(int n,vector<int> arr)
    {
        if(n==0)
        {
            return false;
        }
        else
        {
            int k = accumulate(arr.begin()+n-1,arr.end(),0);
            int r = accumulate(arr.begin(),arr.begin()+n-1,0);
            if(k==r)
            {
                return true;
            }
            else
            {
                return part(n-1,arr);
            }
            
            
            
        }
    }
    */
    bool part(int n,vector<int> arr,int sum)
    {
        if(sum == 0)
        {
            return true;
        }
        else if(n==0 && sum!=0)
        {
            return false;
        }
        if (arr[n-1]>sum)
        {
            return part(n-1,arr,sum);
        }
        else
        {
            return (part(n-1,arr,sum) || part(n-1,arr,sum-arr[n-1]));
        }
        
    }
    int equalPartition(int N, int a[])
    {
        // code here
        vector<int> arr(a,a+N);
        sort(arr.begin(),arr.end());
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0)
        {
            return 0;
        }
        else
        {
            sum = sum/2;  
            if(part(N,arr,sum)==true)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        
    }
};
