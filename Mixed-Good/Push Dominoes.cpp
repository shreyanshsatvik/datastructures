class Solution {
public:
    string pushDominoes(string s) {
        string ans = "";
        int forces[s.size()];
        
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
            {
                count =s.size();
            }
            else if(s[i]=='L')
            {
                count = 0;
            }
            else
            {
                count = max(count-1,0);
            }
            forces[i] = count;
        }
        count =0;
        for(int i = s.size()-1;i>=0;i--)
        {
            if(s[i]=='L')
            {
                count = s.size();
            }
            else if(s[i]=='R')
            {
                count = 0;
            }
            else
            {
                count = max(count-1,0);
            }
            forces[i] -= count;
        }
        for(int i=0;i<s.size();i++)
        {
            if(forces[i]>0)
            {
                ans += 'R';
            }
            else if(forces[i]<0)
            {
                ans += 'L';
            }
            else
            {
                ans += '.';
            }
        }
        return ans;
    }
};
