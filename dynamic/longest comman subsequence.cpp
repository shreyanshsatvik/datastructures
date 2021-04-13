class Solution{
    public:
        
        int lcs(int x, int y, string s1, string s2)
        {
            if(s1.size()==0 || s2.size()==0)
            {
                return 0;
            }
            else
            {
                int k=0;
                vector<vector<int>> arr(x+1,vector<int>(y+1));
                
                for(int i=0;i<x+1;i++)
                {
                    for(int j=0;j<y+1;j++)
                    {
                        if(i==0 || j==0)
                        {
                            arr[i][j] =0;
                        }
                        else
                        {
                            if(s1[i-1]==s2[j-1])
                            {
                                arr[i][j] = 1+ arr[i-1][j-1];    
                            }
                            else if(s1[i-1]!=s2[j-1])
                            {
                                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                            }
                        }
                    }
                    
                }
                return arr[x][y];
                
            }
            
            
        }
        
        
        
        
        
    
};
