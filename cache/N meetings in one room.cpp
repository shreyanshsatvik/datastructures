lass Solution
{
    public:
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> arr(n,vector<int>(n,2));
        
        for(int i=0;i<n;i++)
        {
            arr[i][0] = start[i];
            arr[i][1] = end[i];
            
        }
       
        sort(arr.begin(),arr.end(),[](auto &left, auto &right) {
        return left[1] < right[1]; });
        int count = 1;
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(arr[i][1]<=arr[j][0])
            {
                
                
                count++; 
                i = j;
                
            }
        }
        
        
        return count;
        
    }
};
