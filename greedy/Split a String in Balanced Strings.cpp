class Solution {
public:
    int balancedStringSplit(string s) {
        
        int ans = 0;
        if(s.size()==1)
        {
            return 0;
        }
        for(int i=0;i<s.size()-1;i++)
        {
            string str = "";
            str = str+s[i];
            for(int j=i+1;j<s.size();j++)
            {
                str += s[j];
                if(count(str.begin(),str.end(),'L')==count(str.begin(),str.end(),'R') && str.size()!=0)
                {
                    ans++;
                    cout<<str<<endl;
                    i=j;
                    break;
                }
            }
        }
        return ans;
        
    }
};
