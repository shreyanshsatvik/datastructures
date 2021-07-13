class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26,0);
        for(auto i:p)
        {
            mp[i-'a']++;
        }
        
        vector<int> arr;
        if(p.size()>s.size())
        {
            return arr;
        }
        int p_s = p.size();
        int lptr = 0;
        int rptr = p_s-1;
        vector<int> mp1(26,0);
        for(int i=0;i<p_s;i++)
        {
            mp1[s[i]-'a']++;
        }
        while(rptr-lptr==p_s-1 && rptr<s.size())
        {
            if(mp1==mp)
            {
                arr.push_back(lptr);
                
            }
        
            mp1[s[lptr]-'a']--;
            lptr++;
            rptr++;
            if(rptr<s.size())
            {
                mp1[s[rptr]-'a']++;
            }
        }
        return arr;
    }
};
