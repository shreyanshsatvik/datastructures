class Solution {
public:
   
    bool wordPattern(string pattern, string s) {
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
        
        vector<string> str;
        vector<string> full_str;
        string ss = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(count(str.begin(),str.end(),ss)==0)
                {
                    str.push_back(ss);
                }
                full_str.push_back(ss);
                ss = "";
                continue;
            }
            
            ss += s[i];
            if(i==s.size()-1)
            {
                if(count(str.begin(),str.end(),ss)==0)
                {   
                    str.push_back(ss);
                }
                full_str.push_back(ss);
            }
        }
        
        multimap<int,int> mp2;
        for(int i=0;i<str.size();i++)
        {
            for(int j=0;j<full_str.size();j++)
            {
                if(str[i]==full_str[j])
                {
                    mp2.insert(make_pair(i,j));
                }
            }
        }
        if(mp2==mp)
        {
            return true;
        }
        return false;
        
    }
};
