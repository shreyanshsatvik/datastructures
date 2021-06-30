class Solution {
public:
    string make_string(string s,int start,int end)
    {
        string ans = "";
        for(int i=start;i<=end;i++)
        {
            ans += s[i];
        
        }
        return ans;
    }
        
    string longestPalindrome(string s) {
        int ans =0;
        string str="";
        vector<vector<int>> arr(s.size(),vector<int>(s.size(),0));
        int n = s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                {
                    arr[i][j] = 1;
                    if(arr[i][j]>ans)
                    {
                        str = s[i];
                        ans = arr[i][j];
                    }
                }
                else if(j-i==1)
                {
                    if(s[i]==s[j])
                    {
                        arr[i][j] = 1;
                        if(j-i+1>ans)
                        {
                            str = make_string(s,i,j);
                            ans = str.size();
                        }
                        
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(arr[i+1][j-1]==1)
                        {
                            arr[i][j] = 1;
                            if(j-i+1>ans)
                            {
                                str = make_string(s,i,j);
                                ans = str.size();
                            }
                        }
                    }
                }
            }
        }
        return str;
        
    }
};
