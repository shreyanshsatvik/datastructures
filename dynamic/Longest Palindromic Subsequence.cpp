class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
    vector<vector<int>> arr(s.size()+1,vector<int>(s.size()+1));
    string s1 = s;
    reverse(s1.begin(),s1.end());
    int n = s.size();
    
    for(int i=0;i<n+1;i++)
    {
        arr[i][0] = 0;
        arr[0][i] = 0;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s[i-1]==s1[j-1])
            {
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);       
               
            }
        }
    }
    
    
    
    return arr[n][n];
    
        
    }
};
