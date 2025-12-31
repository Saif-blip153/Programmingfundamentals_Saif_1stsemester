#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double pi=3.14159;
	cout<<fixed<<setprecision(3);
	cout<<setw(10)<<setfill('-')<<pi<<endl;
	return 0;
}
