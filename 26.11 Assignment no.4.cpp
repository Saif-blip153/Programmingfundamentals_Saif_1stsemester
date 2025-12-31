#include<iostream>
using namespace std;
int main()
{
    cout<<"My name is Muhammad Saif"<<endl;
    //This is my name
    cout<<endl;
    cout<<"My Sap ID is 72395"<<endl;
    //This is my SAP ID
    cout<<endl;
    int choice, num, start, end;
    char check, rep;
    do{
        cout<<"Please Enter your operation"<<endl;
        cout<<"Press 1 for checking if number is even or odd"<<endl;
        cout<<"Press 2 for checking if it's prime or not"<<endl;
        cout<<"Press 3 for checking if it is uppercase or lowercase "<<endl;
        cout<<"Press 4 for reverse operation of a number"<<endl;
        cout<<"Press 5 for printing a descending right angle triangle"<<endl;
        cout<<"Press any number between 1 and 5 to perform a specific task from above"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Please enter your designated number"<<endl;
            cin>>num;
            if(num%2==0)
            {
                cout<<"The given number ("<<num<<") is even"<<endl;
            }
            else
            {
                cout<<"The given number ("<<num<<") is odd"<<endl;
            }
            break;
        case 2:
        {
            int x=1;
            cout<<"Enter your number to check if its prime or not"<<endl;
            cin>>num;
            if(num < 2){
                cout<<"Num should be greater than 1"<<endl;
            }
            else{
                for(int i=2;i<num;i++){
                    if(num%i== 0){
                        x=0;
                        break;
                    }
                }
                if (x==1)
                    cout<<num<<" is Prime"<<endl;
                else
                    cout<<num<<" is not Prime"<<endl;
            }
            break;
        }
        case 3:
            cout<<"Enter an alphabet to check if it is uppercase or lowercase"<<endl;
            cin>>check;
            if(check >= 'A'|| check <= 'Z')
            {
                cout<<"The given alphabet ("<<check<<") is uppercase"<<endl;
            }
            else if(check >= 'a' || check <= 'b')
            {
                cout<<"The given alphabet ("<<check<<") is lowercase"<<endl;
            }
            else
            {
                cout<<"Invalid Text"<<endl;
            }
            break;
        case 4:
            cout<<"Choose a number for reverse multiplication"<<endl;
            cin>>num;
            cout<<"Enter a starting range"<<endl;
            cin>>start;
            cout<<"Enter an ending range"<<endl;
            cin>>end;
            for(int i=start;i>=end;i--)
            {
                cout<<num<<" x "<<i<<" = "<<num*i<<endl;
            }
            break;
        case 5:
            cout<<"Descending Right Angle Triangle"<<endl;
            cin>>num;
            for(int i=num;i>=1;i--)
            {
                for(int j=1;j<=i;j++)
                {
                    cout<<"*";
                }
                cout<<endl;
            }
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
        cout<<"Do you want to continue to perform tasks (y/Y)"<<endl;
        cin>>rep;
    } while(rep=='y'||rep=='Y');
    cout<<"Thanks for using this program"<<endl;
    return 0;
}

