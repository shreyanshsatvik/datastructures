class Solution {
public:
    bool decr(vector<int> arr)
    {
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])
            {
                return false;
            }
        }
        return true;
    }
    int maxProfit(vector<int>& prices) {
       
        int ans =0;
        int minn = prices[0];
        int maxx = 0;
        if(prices.size()<=1)
        {
            return 0;
        }
        if(decr(prices))
        {
            return 0;
        }
        for(int i=1;i<prices.size();i++)
        {
            
            if(prices[i]>minn)
            {
                maxx = prices[i];
                if(maxx-minn>ans)
                {
                    ans = maxx-minn;
                }
            }
            else
            {
                minn = prices[i];
            }
            
            
        }
        
        return ans;
    }
};
