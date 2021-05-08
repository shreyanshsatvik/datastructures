class Solution {
public:
    int minDistance(string word1, string word2) 
        
    {
        
        int n1= word1.size();
        int n2 = word2.size();
        if(n1==0)
        {
            return n2;
        }
        if(n2==0)
        {
            return n1;
        }
        if(n1==0 && n2==0)
        {
            return 0;
        }
        if(word1==word2)
        {
            return 0;
        }
        if(n1==1 && n2==1 &&word1!=word2)
        {
            return 2;
        }
            
        
        vector<vector<int>> arr(n1+1,vector<int>(n2+1));
        
        for(int i=1;i<n1+1;i++)
        {
            arr[i][0] = i;
        }
        for(int i=1;i<n2+1;i++)
        {
            arr[0][i] = i;
        }
        arr[0][0] = 0;
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    arr[i][j] = arr[i-1][j-1];
                }
                else
                {
                    int insert = arr[i][j-1]+1;
                    arr[i][j] = min(arr[i-1][j]+1,insert);
                    
                    
                }
                
            }
        }
        return arr[n1][n2];
    }
};
