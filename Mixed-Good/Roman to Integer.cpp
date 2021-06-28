class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp.insert(make_pair('I',1));
        mp.insert(make_pair('V',5));
        mp.insert(make_pair('X',10));
        mp.insert(make_pair('L',50));
        mp.insert(make_pair('C',100));
        mp.insert(make_pair('D',500));
        mp.insert(make_pair('M',1000));
        
        int num=0;
        bool flag = false;
        for(int i=0;i<s.size()-1;i++)
        {
            if(mp[s[i+1]]>mp[s[i]] && s.size()>=i+1)
            {
                i = i+1;
                num += mp[s[i]]-mp[s[i-1]];
                if(i==s.size()-1)
                {
                    flag = true;
                }
            }
            else
            {
                num+= mp[s[i]];
            }
        }
        if(!flag)
        num += mp[s[s.size()-1]];
        
        return num;
    }
};
