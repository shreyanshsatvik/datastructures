class Solution {
public:
    bool is_palindrome(string s,int maxx,int index)
    {
        string ans = "";
        for(int i=index-maxx;i<index;i++)
        {
            ans+= s[i];
        }
        string ans2 = ans;
        reverse(ans2.begin(),ans2.end());
        if(ans==ans2)
        {
            return true;
        }
        return false;
        
    }
    string longestPalindrome(string s) {
        if(s.size()<=1)
        {
            return s;
        }
        vector<vector<int>> arr(s.size()+1,vector<int>(s.size()+1,0));
        int index;
        int maxx = 0;
        string ss = s;
        reverse(ss.begin(),ss.end());
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=1;j<s.size()+1;j++)
            {
                if(ss[j-1]==s[i-1])
                {
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                if(maxx<arr[i][j] && is_palindrome(s,arr[i][j],i))
                {
                    maxx = arr[i][j];
                    index = i;
                }
            }
        }
        string ans = "";
        for(int i=index-maxx;i<index;i++)
        {
            ans+= s[i];
        }
        return ans;
    }
};
