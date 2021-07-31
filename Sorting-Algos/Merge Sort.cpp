class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int n1 = mid-l+1;
         int n2 = r-mid;
         int a[n1];
         int b[n2];
         for(int i=0;i<n1;i++)
         {
             a[i] = arr[l+i];
         }
         for(int i=0;i<n2;i++)
         {
             b[i] = arr[mid+1+i];
         }
         int i=0;
         int j=0;
         int k=l;
         while(i<n1 && j<n2)
         {
             if(a[i]<b[j])
             {
                 arr[k] = a[i];
                 i++;
                 k++;
             }
             else
             {
                 arr[k] = b[j];
                 j++;
                 k++;
             }
         }
         while(i<n1)
         {
             arr[k] = a[i];
             i++;
             k++;
         }
         while(j<n2)
         {
             arr[k] = b[j];
             j++;
             k++;
         }
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(r<=l) return;
        int mid = (r+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
