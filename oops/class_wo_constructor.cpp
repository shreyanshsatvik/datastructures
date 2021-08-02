#include<bits/stdc++.h>
using namespace std;
class student{
	
	string name;
	public:
		
		int id;
		int age;
		string ss;
		void setName(string s)
		{
			name = s;
		}
		void getName()
		{
			//ss = name;
			cout<<name<<endl;
		}
		 
		void display()
		{
			cout<<ss<<" "<<age<<" "<<id<<endl;
		}
};

int main()
{
	
	student arr[3];
	for(int i=0;i<3;i++)
	{
		string s;
		cin>>s;
		arr[i].setName(s);
		cin>>arr[i].age;
		
		cin>>arr[i].id;
	
		
	}
	for(int i=0;i<3;i++)
	{
		arr[i].display();
	}
	//s.display();	
	
}
