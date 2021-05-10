class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> prime(n,true);
        
        if(n<=1)
        {
            return 0;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==true)
            {
                
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        
        return count(prime.begin(),prime.end(),true)-2;
        
    }
};
