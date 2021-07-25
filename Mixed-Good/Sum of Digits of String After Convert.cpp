class Solution {
    
public:
    int sum(int n)
    {
        int ans = 0;
        while(n>0)
        {
            ans += n%10;
            n = n/10;
        }
        return ans;
    }
    int getLucky(string s, int k) {
        
        int n = 0;
        for(int i=0;i<s.size();i++)
        {
            int l =(s[i]-'a'+1);
            n+= sum(l);
        }
    
        k = k-1;
        while(k>0)
        {
            n = sum(n);
            k--;
        }
        return n;
        
        
    }
};
