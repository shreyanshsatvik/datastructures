class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        
        map<int,long> mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        long long ans = 0;
        for(auto i:mp)
        {
            for(auto j:mp)
            {
                int a = i.first; 
                int b = j.first;
                int c = target-a-b;
                if(mp.find(c)==mp.end())
                {
                    continue;
                }
                if(a==b && b==c)
                {
                    ans += mp[a]*(mp[a]-1)*(mp[a]-2)/6;
                }
                else if(a==b && b!=c)
                {
                    ans += mp[a]*(mp[a]-1)/2*mp[c];
                }
                else if(a<b && b<c)
                {
                    ans += mp[a]*mp[b]*mp[c];
                }
                    
            }
        }
      return ans%int(1e9 + 7);
        
    }
    
};
