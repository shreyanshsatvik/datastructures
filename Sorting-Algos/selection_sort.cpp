class Solution
{
    public:
    int select(int arr[], int i,int n)
    {
        // code here such that selectionSort() sorts arr[]
        
        int min = arr[i];
        int ind = i;
        for(int j=i;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                ind = j;        
            }
        }
        return ind;
        
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       
       for(int i=0;i<n-1;i++)
       {
           int ind = select(arr,i,n);
           swap(&arr[i],&arr[ind]);
           
       }
    }
};
