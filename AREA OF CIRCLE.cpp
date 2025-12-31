// CALCULATING THE AREA AND CIRCUMFERENCE OF THE CIRCLE
#include<iostream>
using namespace std;
double calareacircle(double pi,double r);
int main()
{
	double pi=3.14;
	double r;
	cout<<"Enter radius of Circle"<<endl;
	cin>>r;
	cout<<"Area of circle is:"<<pi*(r*r)<<endl;
	cout<<"Circumference of circle:"<<2*(pi*r)<<endl;		
}
