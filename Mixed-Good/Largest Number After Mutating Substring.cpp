class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string ans = "";
        int flag = -1;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]-'0'<= change[num[i]-'0'] && (flag==-1 ||flag== i-1) )
            {
                if(flag==-1 && num[i]-'0'== change[num[i]-'0'] ) 
                {
                    ans+=num[i];
                    continue;
                }
                int n = change[num[i]-'0'];
              
                //cout<<n<<endl;
                ans += to_string(n);
                flag = i;
            
                continue;
            }
            ans += num[i];
            
            
        }
        return ans;
        
    }
};
