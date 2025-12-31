#include<iostream>
using namespace std;
double calAreaRectangle (double length,double width);
int main(){
	double length=0;
	double width=0;
	double area=0;
	cout<<"Enter the length of the rectangle(cm):";
	cin>>length;
	cout<<"Enter the width of the rectangle(cm):";
	cin>>width;
	area=calAreaRectangle(length,width);
	cout<<"Area of rectangle="<<area<<endl;
//	cout<<"Area (length*width):"<<area<<"sq cm"<<endl;
	return 0;
}//end of the main
double calAreaRectangle(double l,double w)
{
	return l*w;
}//end of the fuction calArea
	

