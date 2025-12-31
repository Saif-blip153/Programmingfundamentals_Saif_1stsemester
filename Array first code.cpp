#include<iostream>
using namespace std;
int main()
{
	int marks[10];
	for(int i=0;i<10;i++)
	{
		marks[i]=i;
	}
	cout<<"Values stored in the array"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"Marks["<<i<<"]="<<marks[i]<<endl;
	}
	return 0;
}
