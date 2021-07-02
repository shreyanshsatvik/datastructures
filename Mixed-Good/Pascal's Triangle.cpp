class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        ans.push_back({1});
        if(numRows>=2)
        {
    
            ans.push_back({1,1});
            if(numRows>=3)
            {
                for(int i=2;i<numRows;i++)
            {
                vector<int> arr;
                for(int j=0;j<=i;j++)
                {
                    if(j==0||j==i)
                    {
                        arr.push_back(1);
                    }
                    else
                    {
                        arr.push_back(ans[i-1][j-1]+ans[i-1][j]);
                    }
                    
                }
                ans.push_back(arr);

            }
            }
            
        }
        return ans;
        
        
        
        
    }
};
