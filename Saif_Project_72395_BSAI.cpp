#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
    int adminchoice, customerchoice, mainchoice, pass; 
    int submenuChoices[100]; // Better name for array storing all submenu choices
    // char rep; // REMOVE - not used
    
    do{
        // DISPLAY MAIN HEADER
        cout<<setfill('=')<<setw(40)<<""<<endl;
        cout<<setfill(' ')<<setw(30)<<right<<"VENDING MACHINE SYSTEM"<<endl;
        cout<<setfill('=')<<setw(40)<<""<<endl;
        
        // DISPLAY MAIN MENU
        cout<<setfill('=')<<setw(40)<<""<<endl;
        cout<<setfill(' ')<<setw(25)<<right<<"MAIN MENU"<<endl;
        cout<<setfill('=')<<setw(40)<<""<<endl;
        cout<<"1. ADMIN MENU"<<endl;
        cout<<"2. CUSTOMER MENU"<<endl;    // Fixed comment inconsistency
        cout<<"3. EXIT"<<endl;
        cout<<setfill('=')<<setw(40)<<""<<endl;
        cout<<setfill(' ')<<setw(25)<<right<<"CHOOSE OPTION"<<endl;
        cout<<setfill('=')<<setw(40)<<""<<endl;
        cin >>mainchoice;  // Get MAIN MENU choice (not customer choice)
        
        switch(mainchoice)
        {
            case 1:  // Admin Menu
                while(true)   // while loop (not for loop)
                {
                    cout<<"ENTER PASSWORD : ";
                    cin >>pass;
                    if(pass == 8411)
                    {
                        cout<<"ACCESS GRANTED"<<endl;
                        do{
                            // ... admin menu code ...
                            cin >>adminchoice;
                            
                            if(adminchoice == 16) {
                                cout<<"RETURNING TO MAIN MENU..."<<endl;
                                break;
                            }
                            
                            switch(adminchoice)
                            {
                                case 1:
                                    // ... admin submenus ...
                                    cin >> submenuChoices[0];  // Better array name
                                    // ... rest of code ...
                            }
                        } while(adminchoice != 16);
                        break;
                    }
                    else
                    {
                        cout<<"ACCESS DENIED TRY AGAIN !"<<endl;
                    }
                }
                break;
                
            case 2:  // CUSTOMER MENU (not USER MENU)
                do {
                    // DISPLAY CUSTOMER MENU
                    cout<<setfill('=')<<setw(40)<<""<<endl;
                    cout<<setfill(' ')<<setw(25)<<right<<"CUSTOMER MENU"<<endl;  // Fixed
                    cout<<setfill('=')<<setw(40)<<""<<endl;
                    // ... customer menu options ...
                    cin >>customerchoice;
                    
                    if(customerchoice == 10) {
                        cout<<"RETURNING TO MAIN MENU..."<<endl;
                        break;
                    }
                    
                    switch(customerchoice)
                    {
                        // ... customer submenus using submenuChoices[15] to [23] ...
                    }
                } while(customerchoice != 10);
                break;
                
            case 3:
                cout<<setfill('=')<<setw(40)<<""<<endl;
                cout<<setfill(' ')<<setw(25)<<right<<"THANK YOU !"<<endl;
                cout<<setfill('=')<<setw(40)<<""<<endl;
                return 0;
                
            default :
                cout<<"INVALID OPTION ! PLEASE SELECT OPTION BETWEEN (1-3)"<<endl;
        }
    } while(true);
}
