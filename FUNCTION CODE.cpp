#include<iostream>
using namespace std;

int sum(int a,int b)
{
	int c=a+b;
	return c;
}
int main()
{
int n1,n2;
cout<<"Enter your first number"<<endl;
cin>>n1;
cout<<"Enter your second number"<<endl;
cin>>n2;
cout<<"Result is:"<<sum(n1,n2);
return 0;
}

