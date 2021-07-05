class Solution {
public:
    string make_string(string s,int k,int j)
    {
        string ans = "";
        for(int i=k;i<=j;i++)
        {
            ans += s[i];
        }
        return ans;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> arr(s.size(),vector<bool>(s.size(),false));
        int n= s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                {
                    arr[i][j] = true;
                }
                else if(i+1==j)
                {
                    if(s[i]==s[j])
                    {
                        arr[i][j] = true;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(arr[i+1][j-1])
                        {
                            arr[i][j] = true;
                        }
                    }
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s,0,curr,ans,arr);
        
        
        return ans;
        
    }
    void backtrack(string s,int start,vector<string> &curr,vector<vector<string>> &ans,vector<vector<bool>> &visited)
    {
        if(s.size()==start)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(visited[start][i])
            {
                curr.push_back(s.substr(start,i-start+1));
                backtrack(s,i+1,curr,ans,visited);
                curr.pop_back();
            }
        }
    }
};
