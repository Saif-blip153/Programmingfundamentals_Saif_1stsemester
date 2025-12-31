#include<iostream>
using namespace std;
int main(){
	int pass;
	while(true)
	{
		cout<<"Enter password:";
		cin>>pass;
		if(pass==8411)
		{
			cout<<"Access granted"<<endl;
			break;
		}
		else
		{
			cout<<"Invalid, Try again"<<endl;
		}
	}
	return 0;
}
