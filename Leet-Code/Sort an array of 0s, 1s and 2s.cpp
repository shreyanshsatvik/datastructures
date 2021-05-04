class Solution
{
    public:
    void sort012(int a[], int n)
    {
        vector<int> arr(a,a+n);
        int a1 = count(arr.begin(),arr.end(),0);
        int a2 = count(arr.begin(),arr.end(),1);
        int a3 = count(arr.begin(),arr.end(),2);
        for(int i=0;i<a1;i++)
        {
            a[i] = 0;
        }
        for(int i=a1;i<a1+a2;i++)
        {
            a[i] = 1;
        }
        for(int i=a1+a2;i<a1+a2+a3;i++)
        {
            a[i] = 2;
        }
        
        
    }
    
};
