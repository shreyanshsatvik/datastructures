#include<bits/stdc++.h>
using namespace std;

int catlan(int n)
{
	vector<int> arr(n);
	arr[0] = 1;
	arr[1] = 1;
	
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			arr[i] += arr[j]*arr[i-j-1];
		}	
	}
	
	return arr[n-1];
	
	
}

int main()
{
	int n;
	cout<<"Enter Number to find its catlan"<<endl;
	cin>>n;
	cout<<catlan(n)<<endl;
}
