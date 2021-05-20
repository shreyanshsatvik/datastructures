
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    long long sum = 0;
    if(n==1)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    int temp_sum = 0;
    int temp = sum;
    for(int i=0;i<n-1;i++)
    {
       temp_sum += a[i];
       temp = sum- temp_sum-a[i+1];
       if(temp==temp_sum)
       {
           return i+2;
       }
    }
    return -1;
    
}

};
