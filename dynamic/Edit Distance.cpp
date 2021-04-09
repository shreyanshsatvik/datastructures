// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        
        vector<vector<int>> arr(s.size()+1,vector<int>(t.size()+1));
        for (int i=0;i<=s.size();i++)
        {
            for(int j=0; j<= t.size();j++)
            {
                
                if(i==0 && j==0)
                {
                    arr[i][j] = 0;
                }
                else if(i==0)
                {
                    arr[i][j] = j;
                }
                else if(j ==0)
                {
                    arr[i][j] = i;
                }
                else if(s[i-1]!=t[j-1] && (i>0 && j>0))
                {
                    int in = arr[i-1][j]+1;
                    int rem = arr[i][j-1]+1;
                    int rep = arr[i-1][j-1]+1;
                    
                    int m = min(in ,rem);
                    arr[i][j] = min(m,rep);
                }
                else if(s[i-1]==t[j-1] && (i>0 && j>0))
                {
                    int di = arr[i-1][j-1];
                    arr[i][j] = di;
                 }
                
            }
        }
        return arr[s.size()][t.size()];
        
        
    }
};
