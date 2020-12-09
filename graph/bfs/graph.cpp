#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;

    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<=6;i++)
    {
        cout<<i<<"->";
        for(auto  j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

      
}