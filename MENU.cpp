#include<iostream>
using namespace std;
int main (){
	int choice;
	int total = 0;
	char again;
	do{
	cout<<"*****Menu*****"<<endl;
	cout<<"Burger"<<endl;
	cout<<"Shawarma"<<endl;
	cout<<"Pizza"<<endl;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"Burger Rs.300"<<endl;
		total+=300;
		break;
		case 2:
			cout<<"Shawarma Rs.150"<<endl;
			total+=150;
			break;
			case 3:
				cout<<"Pizza Rs.500"<<endl;
				total+=500;
				break;
				default:
					cout<<"Sorry not in our menu"<<endl;
					break;
	}
	cout<<"Do u want anything else"<<endl;
	cin>>again;
    } while(again=='y'|| again=='y');
	cout<<"Your total bill is"<<total<<endl;  
	return 0;
}
