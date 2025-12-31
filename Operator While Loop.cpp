#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"Enter Starting Range";
	cin>>a;
	cout<<"Enter ending range";
	cin>>b;
	int sum=0;
	int i=a;
	while(i<=b)
	{
		cout<<i<<endl;
		sum+=i;
		i++;
		
	}
	cout<<"Sum="<<sum<<endl;
}
