#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student
{
	int roll;
	float marks,avg;
	char grade;
	string name;
};
int main()
{
	student a,b,c;
	cout<<"Enter Roll Number Of 3 Students : "<<endl;
	cin >>	a.roll>>b.roll>>c.roll;
	cout<<"Enter Marks Of 3 Students : "<<endl;
	cin >> a.marks>>b.marks>>c.marks;
	cout<<"Enter Avg Of 3 Student : "<<endl;
	cin >> a.avg>>b.avg>>c.avg;
	cout<<"Enter Grade Of 3 Student : "<<endl;
	cin >> a.grade>>b.grade>>c.grade;
	cin.ignore();
	cout<<"Enter Names Of 3 Students : "<<endl;
	getline(cin, a.name);
	getline(cin, b.name);
	getline(cin, c.name);
	cout<<setfill('=')<<setw(50)<<""<<endl;
	cout<<"NAME "<<setfill(' ')<<setw(15)<<"NAME"<<setfill(' ')<<setw(15)<<"NAME"<<endl;
	cout<<a.name<<setfill(' ')<<setw(15)<<b.name<<setfill(' ')<<setw(15)<<c.name<<endl;
	cout<<"ROLL:NO"<<setfill(' ')<<setw(15)<<"ROLL:NO"<<setfill(' ')<<setw(15)<<"ROLL:NO"<<endl;
	cout<<a.roll<<setfill(' ')<<setw(15)<<b.roll<<setfill(' ')<<setw(15)<<c.roll<<endl;
	cout<<"MARKS"<<setfill(' ')<<setw(15)<<"MARKS"<<setfill(' ')<<setw(15)<<"MARKS"<<endl;
	cout<<a.marks<<setfill(' ')<<setw(15)<<b.marks<<setfill(' ')<<setw(15)<<c.marks<<endl;
	cout<<"AVERAGE"<<setfill(' ')<<setw(15)<<"AVERAGE"<<setfill(' ')<<setw(15)<<"AVERAGE"<<endl;
	cout<<a.grade<<setfill(' ')<<setw(15)<<b.grade<<setfill(' ')<<setw(15)<<c.grade<<endl;
	cout<<setfill('=')<<setw(50)<<""<<endl;

	return 0;
}
