#include<iostream>
using namespace std;
int main(){
	int age;
	cout<<"Enter your age"<<endl;
	cin>>age;
	if (age>=16){
		cout<<"You are eligible"<<endl;
		}else{
			if (age<16)
				cout<<"You are NOT eligible"<<endl;
				return 0;
		}
