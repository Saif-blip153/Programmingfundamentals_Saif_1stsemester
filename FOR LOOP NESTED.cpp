#include<iostream>
using namespace std;
int main (){
	int choice;
	cout<<"*****Menu*****"<<endl;
	cout<<"Burger Rs.300"<<endl;
	cout<<"Shawarma Rs.150"<<endl;
	cout<<"Pizza Rs.500"<<endl;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"Burger"<<endl;
		break;
		case 2:
			cout<<"Shawarma"<<endl;
			break;
			case 3:
				cout<<"Pizza"<<endl;
				break;
				default:
					cout<<"Sorry not in our menu"<<endl;
					break;
	}
	return 0;
}
