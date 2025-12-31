#include<iostream>
using namespace std;
int main(){
	int total,choice=0;
	char again;
	do{
		cout<<"Choose Your Options"<<endl;
		cout<<"Anda Rs.50"<<endl;
		cout<<"Paratha Rs.70"<<endl;
		cout<<"Chai Rs.70"<<endl;
		cout<<"Biscuit Rs.40"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			cout<<"Anda Rs.50"<<endl;
			total+=50;
			break;
			case 2:
				cout<<"Paratha Rs.70"<<endl;
				total+=70;
				break;
				case 3:
					cout<<"Chai Rs.70"<<endl;
					total+=70;
					break;
					case 4:
						cout<<"Biscuit Rs.40"<<endl;
						total+=40;
						break;
						default:							
                           cout<<"Item not available"<<endl;
							break;}
						cout<<"Do you want anything else(yes/no)"<<endl;
						cin>>again;}
						while(again=='y'||again=='y');
						cout<<"Your total bill is"<<total<<endl;
						cout<<"Thanks for Visiting"<<endl;						
						return 0;
			}
			
		
						
						
			
	
