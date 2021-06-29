class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(make_pair(start[i],end[i]));
        }
        
        sort(arr.begin(),arr.end(),[](auto &start,auto &end)
        {
            return start.second<end.second;
        });
        if(n==1)
        {
            return 1;
        }
        int count = 0;
        int prev = 0;
        for(int i=0;i<n;i++)
        {
            
            if(prev<arr[i].first)
            {
                prev = arr[i].second;
                count++;
            
            }
            
            
        }
        
        
        
        return count;
        
    }
};
