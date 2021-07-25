#include<bits/stdc++.h>
using namespace std;
int longestSubSeg(int a[],int n,int k)
{
    
    int lptr=0;
    int rptr=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            lptr = i;
            rptr =i+1;
            break;
        }
    }

    int x = k;
    int maxx = 0;
    while(rptr<n)
    {
        
        if(x==0 && a[rptr]==0)
        {
            
            maxx = max(maxx,rptr-lptr+1);
            lptr = rptr-1;
            x= k;
        }
        if(a[rptr]==0)
        {
            x--;
        }
        rptr++;
        
    }
        
    
    return maxx;
}
int main()
{
    int a[] = { 1, 0, 0, 1, 0, 1, 0, 1 };
    int k = 2;
    int n = sizeof(a) / sizeof(a[0]);
    cout << longestSubSeg(a, n, k);
    return 0;
    
    
}
