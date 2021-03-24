#include<bits/stdc++.h>
using namespace std;

int permutation_factor(int n,int k)
{
	if(k>0)
	{
	vector<int> p(k);
	p[0] = n;
	
	
	
		for(int i=1;i<k;i++)
		{
			p[i] = p[i-1]*(n-i);
		}
		return p[k-1];
	}
	return n;

}
int main()
{
	int n,k;
	cout<<"Enter the value of n and k"<<endl;
	cin>>n;
	cin>>k;
	cout<<permutation_factor(n,k);
}
