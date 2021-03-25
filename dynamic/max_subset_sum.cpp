int maxSubsetSum(vector<int> arr) {


    int curr = arr[0];
    int prev = 0;
    int cur;
    for(int i=1;i<arr.size();i++)
    {
        cur = arr[i]+prev;
        prev = max(curr,prev);
        curr = cur;
    }
    return max(prev,curr);
