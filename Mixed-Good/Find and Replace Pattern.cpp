class Solution {
public:
    multimap<int,int> convt(string pattern)
    {
         vector<int> patt;
        for(int i=0;i<pattern.size();i++)
        {
            if(count(patt.begin(),patt.end(),pattern[i])==0)
            {
                patt.push_back(pattern[i]);
            }
        }
       
        
        multimap <int,int> mp;
        for(int i=0;i<patt.size();i++)
        {
            for(int j=0;j<pattern.size();j++)
            {
                if(patt[i]==pattern[j])
                {
                    mp.insert(make_pair(i,j));

                }
            }
        }
        return mp;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        multimap<int,int> mp = convt(pattern);
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(convt(words[i])==mp)
            {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
        
    }
};
