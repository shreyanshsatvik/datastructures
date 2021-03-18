
#include<bits/stdc++.h>
using namespace std;

int max_subsequence(vector<int> &arr)
{
    int p =arr.size();
    vector<int> l(p,1);
    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && l[i]<l[j]+1)
            {
                l[i] = l[j]+1;
            }
        }
    }

    return *max_element(l.begin(),l.end());





}

int main()
{
    cout<<"Enter Number of Elements:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array:"<<endl;
    vector<int> arr;
    while(n--)
    {
        int k;
        cin>>k;
        arr.push_back(k);
    }
    int l = max_subsequence(arr);
    cout<<"Maximum Subsequence Length:- "<<endl;
    cout<<l<<endl;


}
