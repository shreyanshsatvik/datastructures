class Solution {
public:
    
    int maxProfit(vector<int>& arr) {
        int buy=0;
        int sell =0;
        int profit = 0;
        int i = 0;
        int n = arr.size();
        while(n>i)
        {
            while(n-1>i && arr[i]>arr[i+1])i++;
            buy = arr[i];
            while(n-1>i && arr[i]<arr[i+1])i++;
            sell = arr[i];
            
            profit += sell-buy;
            i++;
        }    
        return profit;
        
    }
};
