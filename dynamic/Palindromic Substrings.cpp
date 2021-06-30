class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> arr(s.size(),vector<int>(s.size(),0));
        int count = 0;
        int n= s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                
                if(i==j)
                {
                    arr[i][j] = 1;
                    count++;
                }
                
                else if(i+1==j)
                {
                    if(s[i]==s[j])
                    {
                        arr[i][j] = 1;
                        count++;
                    }
                    
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(arr[i+1][j-1]==1)
                        {
                            arr[i][j] =1;
                            count++;
                        }
                    }
                }    
            }
        }
        
        return count;
    }
};
