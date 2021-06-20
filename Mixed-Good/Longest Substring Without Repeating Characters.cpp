class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        int count = 1;
        int lptr = 0;
        
        if(s.size()==0)
        {
            return 0;
        }
        if(s.size()==1)
        {
            return 1;
        }
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp.insert(make_pair(s[i],i));
                 count = max(count,i-lptr+1);
            }
            else
            {
                lptr = max(lptr,mp[s[i]]+1);
                mp[s[i]] = i;
                
                count = max(count,i-lptr+1);
            }
           
        }
        return count;
        
        
        
        
        
    }
    
        
        
      
