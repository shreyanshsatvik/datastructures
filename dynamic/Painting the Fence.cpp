

class Solution{
    public:
    
    long long countWays(int n, int k){
        // code here
        vector<long long> same(100000);
        vector<long long> diff(100000);
        long long mod = 1000000007;
        same[0] = 0;
        diff[0] = k;
        
        same[1] = k;
        diff[1] = k*(k-1);
    
       
        
        if(n>=2)
        {
            for(int i=2;i<n;i++)
            {
                same[i] = diff[i-1];
                diff[i] = (diff[i-1]+diff[i-2])*(k-1);
                diff[i] = diff[i]%mod;
            }
        }
        long long ans = (same[n-1] + diff[n-1])%mod;
        return ans;
        
    }
};

