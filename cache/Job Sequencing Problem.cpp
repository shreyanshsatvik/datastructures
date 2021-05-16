class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
    vector<Job> arr1(arr,arr+n);
    vector<int> ans;      
    sort(arr1.begin(),arr1.end(),[](auto &left, auto &right) {
        return (left.profit > right.profit); });
    
    int count = 0;
    int net_profit = 0;
    vector<int> idd;
    int current = 0;
    
    for(int i=0;i<n;i++)
    {
       
        if(count<arr1[i].dead)
        {
        count++;
        net_profit += arr1[i].profit;
        
        
        }
    }
    ans.push_back(count);
    ans.push_back(net_profit);
    //cout<<arr1[0].profit;
    return ans;
        
    } 
};
