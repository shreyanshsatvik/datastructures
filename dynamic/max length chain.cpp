int maxChainLen(struct val p[],int n)
{
//Your code here'
    
    vector<vector<int>> arr1(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        arr1[i][0] = p[i].first; 
        arr1[i][1] = p[i].second;
    }
    sort(arr1.begin(),arr1.end());
    
    vector<int> arr(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr1[i][0]>arr1[j][1] && arr[i]<arr[j]+1)
            {
                arr[i] = arr[j] + 1;
            }
        }
    }
    return *max_element(arr.begin(),arr.end());


}
