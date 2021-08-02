#include<bits/stdc++.h>
using namespace std;
class student{
	string name;
	int id;
	int age;
	public:
		student(string name,int id,int age)
		{
			this->name = name;
			this->age = age;
			this->id = id;
		}
		void display()
		{
			cout<<this->name<<" "<<this->age<<" "<<this->id;
		}
};

int main()
{
	student s = student("Shreyansh",12,1);

	for(int i=0;i<3;i++)
	{
		string s;
		cin>>s;
		int age;
		cin>>age;
		int id;
		cin>>id;
		student a = student(s,age,id);
		a.display();
	
		
	}
	s.display();	
	
}
