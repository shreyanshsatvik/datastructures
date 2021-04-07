class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        sort(coins.begin(),coins.end());
            
        
        vector<vector<int>> arr(coins.size()+1,vector<int>(amount+1));
        
        //vector<int> val(coins.size(),10000);
        
        for(int i=0;i<coins.size()+1;i++)
        {
            for(int j=0; j<amount+1;j++)
            {
                if(i==0 || (i==0 && j==0) )
                {
                    arr[i][j] = 10000;
                    
                }
                else if(j==0 )
                {
                    arr[i][j] = 0;
                }
                
                else if(j<coins[i-1])
                {
                    arr[i][j] = arr[i-1][j];     
                }
                else
                {
                    if(j%coins[i-1]==0)
                    {
                        arr[i][j] = j/coins[i-1];
                    }
                    else
                    {
                        arr[i][j] = min(arr[i-1][j],(arr[i][j-coins[i-1]])+1);
                    }
                    
                    
                }
                
            }
        }
        if(arr[coins.size()][amount]>=10000)
        {
            return -1;
        }
        return arr[coins.size()][amount];
        
        
        
        
        
        
    }
};
