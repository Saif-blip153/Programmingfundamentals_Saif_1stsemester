#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// Function declarations
void displayHeader(const string& title);
void displayAdminMenu();
void displayCustomerMenu();
void adminSubMenu(int choice);
void customerSubMenu(int choice);

int main() {
    int mainChoice, adminChoice, customerChoice, password;
    char repeat;
    int subMenuChoices[100]; // Array to store submenu choices
    
    do {
        // DISPLAY MAIN HEADER
        displayHeader("VENDING MACHINE SYSTEM");
        
        // DISPLAY MAIN MENU
        displayHeader("MAIN MENU");
        cout << "1. ADMIN MENU\n";
        cout << "2. CUSTOMER MENU\n";
        cout << "3. EXIT\n";
        displayHeader("CHOOSE OPTION");
        cin >> mainChoice;
        
        switch(mainChoice) {
            case 1: // Admin Menu
                while(true) {
                    cout << "ENTER PASSWORD: ";
                    cin >> password;
                    
                    if(password == 8411) {
                        cout << "ACCESS GRANTED\n";
                        
                        do {
                            displayAdminMenu();
                            cin >> adminChoice;
                            
                            if(adminChoice == 16) {
                                cout << "RETURNING TO MAIN MENU...\n";
                                break;
                            }
                            
                            if(adminChoice >= 1 && adminChoice <= 15) {
                                adminSubMenu(adminChoice);
                            } else {
                                cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-16)\n";
                            }
                        } while(adminChoice != 16);
                        break;
                    } else {
                        cout << "ACCESS DENIED! TRY AGAIN!\n";
                    }
                }
                break;
                
            case 2: // Customer Menu
                do {
                    displayCustomerMenu();
                    cin >> customerChoice;
                    
                    if(customerChoice == 10) {
                        cout << "RETURNING TO MAIN MENU...\n";
                        break;
                    }
                    
                    if(customerChoice >= 1 && customerChoice <= 9) {
                        customerSubMenu(customerChoice);
                    } else {
                        cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-10)\n";
                    }
                } while(customerChoice != 10);
                break;
                
            case 3: // Exit
                displayHeader("THANK YOU!");
                return 0;
                
            default:
                cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-3)\n";
        }
        
        cout << "\nDo you want to continue? (Y/N): ";
        cin >> repeat;
    } while(repeat == 'Y' || repeat == 'y');
    
    return 0;
}

// Function to display headers with consistent formatting
void displayHeader(const string& title) {
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(25) << right << title << endl;
    cout << setfill('=') << setw(40) << "" << endl;
}

// Function to display Admin Menu
void displayAdminMenu() {
    displayHeader("ADMIN MENU");
    cout << "1. ADD ITEM\n";
    cout << "2. VIEW ALL ITEMS\n";
    cout << "3. SEARCH ITEM\n";
    cout << "4. UPDATE ITEM\n";
    cout << "5. DELETE ITEM\n";
    cout << "6. VIEW STOCK\n";
    cout << "7. RESTOCK ITEM\n";
    cout << "8. SET PRICES\n";
    cout << "9. VIEW SALES REPORT\n";
    cout << "10. VIEW TRANSACTION HISTORY\n";
    cout << "11. MANAGE CATEGORIES\n";
    cout << "12. VIEW LOW STOCK ITEMS\n";
    cout << "13. GENERATE REPORTS\n";
    cout << "14. MACHINE SETTINGS\n";
    cout << "15. BACKUP DATA\n";
    cout << "16. BACK TO MAIN MENU\n";
    displayHeader("SELECT OPTION");
}

// Function to display Customer Menu
void displayCustomerMenu() {
    displayHeader("CUSTOMER MENU");
    cout << "1. VIEW ALL ITEMS\n";
    cout << "2. SEARCH ITEM\n";
    cout << "3. PURCHASE ITEM\n";
    cout << "4. VIEW CART\n";
    cout << "5. CHECKOUT\n";
    cout << "6. VIEW PRICES\n";
    cout << "7. VIEW OFFERS\n";
    cout << "8. ADD MONEY\n";
    cout << "9. VIEW BALANCE\n";
    cout << "10. BACK TO MAIN MENU\n";
    displayHeader("CHOOSE OPTION");
}

// Function to handle Admin submenus
void adminSubMenu(int choice) {
    int subChoice;
    
    switch(choice) {
        case 1: // ADD ITEM
            displayHeader("ADD ITEM");
            cout << "1. ADD DRINKS\n";
            cout << "2. ADD SNACKS\n";
            cout << "3. ADD CHOCOLATES\n";
            cout << "4. ADD BISCUITS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "ADDING DRINKS...\n"; break;
                case 2: cout << "ADDING SNACKS...\n"; break;
                case 3: cout << "ADDING CHOCOLATES...\n"; break;
                case 4: cout << "ADDING BISCUITS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 2: // VIEW ALL ITEMS
            displayHeader("VIEW ALL ITEMS");
            cout << "1. VIEW BY CATEGORY\n";
            cout << "2. VIEW BY PRICE\n";
            cout << "3. VIEW BY STOCK\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING BY CATEGORY...\n"; break;
                case 2: cout << "VIEWING BY PRICE...\n"; break;
                case 3: cout << "VIEWING BY STOCK...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 3: // SEARCH ITEM
            displayHeader("SEARCH ITEM");
            cout << "1. SEARCH BY NAME\n";
            cout << "2. SEARCH BY CODE\n";
            cout << "3. SEARCH BY CATEGORY\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "SEARCHING BY NAME...\n"; break;
                case 2: cout << "SEARCHING BY CODE...\n"; break;
                case 3: cout << "SEARCHING BY CATEGORY...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 4: // UPDATE ITEM
            displayHeader("UPDATE ITEM");
            cout << "1. UPDATE PRICE\n";
            cout << "2. UPDATE STOCK\n";
            cout << "3. UPDATE DETAILS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "UPDATING PRICE...\n"; break;
                case 2: cout << "UPDATING STOCK...\n"; break;
                case 3: cout << "UPDATING DETAILS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 5: // DELETE ITEM
            displayHeader("DELETE ITEM");
            cout << "1. DELETE BY CODE\n";
            cout << "2. DELETE BY NAME\n";
            cout << "3. DELETE BY CATEGORY\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "DELETING BY CODE...\n"; break;
                case 2: cout << "DELETING BY NAME...\n"; break;
                case 3: cout << "DELETING BY CATEGORY...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 6: // VIEW STOCK
            displayHeader("VIEW STOCK");
            cout << "1. VIEW DRINKS STOCK\n";
            cout << "2. VIEW SNACKS STOCK\n";
            cout << "3. VIEW CHOCOLATES STOCK\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING DRINKS STOCK...\n"; break;
                case 2: cout << "VIEWING SNACKS STOCK...\n"; break;
                case 3: cout << "VIEWING CHOCOLATES STOCK...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 7: // RESTOCK ITEM
            displayHeader("RESTOCK ITEM");
            cout << "1. RESTOCK DRINKS\n";
            cout << "2. RESTOCK SNACKS\n";
            cout << "3. RESTOCK CHOCOLATES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "RESTOCKING DRINKS...\n"; break;
                case 2: cout << "RESTOCKING SNACKS...\n"; break;
                case 3: cout << "RESTOCKING CHOCOLATES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 8: // SET PRICES
            displayHeader("SET PRICES");
            cout << "1. SET DRINKS PRICES\n";
            cout << "2. SET SNACKS PRICES\n";
            cout << "3. SET CHOCOLATES PRICES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "SETTING DRINKS PRICES...\n"; break;
                case 2: cout << "SETTING SNACKS PRICES...\n"; break;
                case 3: cout << "SETTING CHOCOLATES PRICES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 9: // VIEW SALES REPORT
            displayHeader("SALES REPORT");
            cout << "1. VIEW DAILY SALES\n";
            cout << "2. VIEW MONTHLY SALES\n";
            cout << "3. VIEW YEARLY SALES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING DAILY SALES...\n"; break;
                case 2: cout << "VIEWING MONTHLY SALES...\n"; break;
                case 3: cout << "VIEWING YEARLY SALES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 10: // TRANSACTION HISTORY
            displayHeader("TRANSACTION HISTORY");
            cout << "1. VIEW TODAY'S TRANSACTIONS\n";
            cout << "2. VIEW LAST WEEK TRANSACTIONS\n";
            cout << "3. VIEW ALL TRANSACTIONS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING TODAY'S TRANSACTIONS...\n"; break;
                case 2: cout << "VIEWING LAST WEEK TRANSACTIONS...\n"; break;
                case 3: cout << "VIEWING ALL TRANSACTIONS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 11: // MANAGE CATEGORIES
            displayHeader("MANAGE CATEGORIES");
            cout << "1. ADD CATEGORY\n";
            cout << "2. DELETE CATEGORY\n";
            cout << "3. VIEW CATEGORIES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "ADDING CATEGORY...\n"; break;
                case 2: cout << "DELETING CATEGORY...\n"; break;
                case 3: cout << "VIEWING CATEGORIES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 12: // LOW STOCK ITEMS
            displayHeader("LOW STOCK ITEMS");
            cout << "1. VIEW LOW STOCK ITEMS\n";
            cout << "2. VIEW OUT OF STOCK ITEMS\n";
            cout << "3. SET STOCK THRESHOLD\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING LOW STOCK ITEMS...\n"; break;
                case 2: cout << "VIEWING OUT OF STOCK ITEMS...\n"; break;
                case 3: cout << "SETTING STOCK THRESHOLD...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 13: // GENERATE REPORTS
            displayHeader("GENERATE REPORTS");
            cout << "1. GENERATE SALES REPORT\n";
            cout << "2. GENERATE STOCK REPORT\n";
            cout << "3. GENERATE PROFIT REPORT\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "GENERATING SALES REPORT...\n"; break;
                case 2: cout << "GENERATING STOCK REPORT...\n"; break;
                case 3: cout << "GENERATING PROFIT REPORT...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 14: // MACHINE SETTINGS
            displayHeader("MACHINE SETTINGS");
            cout << "1. CHANGE PASSWORD\n";
            cout << "2. SET MAINTENANCE MODE\n";
            cout << "3. SYSTEM INFO\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "CHANGING PASSWORD...\n"; break;
                case 2: cout << "SETTING MAINTENANCE MODE...\n"; break;
                case 3: cout << "VIEWING SYSTEM INFO...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 15: // BACKUP DATA
            displayHeader("BACKUP DATA");
            cout << "1. BACKUP ALL DATA\n";
            cout << "2. RESTORE DATA\n";
            cout << "3. VIEW BACKUP FILES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "BACKING UP ALL DATA...\n"; break;
                case 2: cout << "RESTORING DATA...\n"; break;
                case 3: cout << "VIEWING BACKUP FILES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
    }
}

// Function to handle Customer submenus
void customerSubMenu(int choice) {
    int subChoice;
    
    switch(choice) {
        case 1: // VIEW ITEMS
            displayHeader("VIEW ITEMS");
            cout << "1. VIEW DRINKS\n";
            cout << "2. VIEW SNACKS\n";
            cout << "3. VIEW CHOCOLATES\n";
            cout << "4. VIEW ALL ITEMS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING DRINKS...\n"; break;
                case 2: cout << "VIEWING SNACKS...\n"; break;
                case 3: cout << "VIEWING CHOCOLATES...\n"; break;
                case 4: cout << "VIEWING ALL ITEMS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 2: // SEARCH ITEM
            displayHeader("SEARCH ITEM");
            cout << "1. SEARCH BY NAME\n";
            cout << "2. SEARCH BY CODE\n";
            cout << "3. SEARCH BY CATEGORY\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "SEARCHING BY NAME...\n"; break;
                case 2: cout << "SEARCHING BY CODE...\n"; break;
                case 3: cout << "SEARCHING BY CATEGORY...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 3: // PURCHASE ITEM
            displayHeader("PURCHASE ITEM");
            cout << "1. BUY DRINKS\n";
            cout << "2. BUY SNACKS\n";
            cout << "3. BUY CHOCOLATES\n";
            cout << "4. BUY BISCUITS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "BUYING DRINKS...\n"; break;
                case 2: cout << "BUYING SNACKS...\n"; break;
                case 3: cout << "BUYING CHOCOLATES...\n"; break;
                case 4: cout << "BUYING BISCUITS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 4: // VIEW CART
            displayHeader("VIEW CART");
            cout << "1. VIEW CART ITEMS\n";
            cout << "2. REMOVE FROM CART\n";
            cout << "3. CLEAR CART\n";
            cout << "4. UPDATE QUANTITY\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING CART ITEMS...\n"; break;
                case 2: cout << "REMOVING FROM CART...\n"; break;
                case 3: cout << "CLEARING CART...\n"; break;
                case 4: cout << "UPDATING QUANTITY...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 5: // CHECKOUT
            displayHeader("CHECKOUT");
            cout << "1. PROCEED TO PAYMENT\n";
            cout << "2. VIEW BILL\n";
            cout << "3. APPLY DISCOUNT\n";
            cout << "4. CANCEL ORDER\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "PROCEEDING TO PAYMENT...\n"; break;
                case 2: cout << "VIEWING BILL...\n"; break;
                case 3: cout << "APPLYING DISCOUNT...\n"; break;
                case 4: cout << "CANCELLING ORDER...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 6: // VIEW PRICES
            displayHeader("VIEW PRICES");
            cout << "1. VIEW DRINKS PRICES\n";
            cout << "2. VIEW SNACKS PRICES\n";
            cout << "3. VIEW CHOCOLATES PRICES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING DRINKS PRICES...\n"; break;
                case 2: cout << "VIEWING SNACKS PRICES...\n"; break;
                case 3: cout << "VIEWING CHOCOLATES PRICES...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 7: // VIEW OFFERS
            displayHeader("VIEW OFFERS");
            cout << "1. VIEW CURRENT OFFERS\n";
            cout << "2. VIEW DISCOUNT CODES\n";
            cout << "3. VIEW SPECIAL DEALS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING CURRENT OFFERS...\n"; break;
                case 2: cout << "VIEWING DISCOUNT CODES...\n"; break;
                case 3: cout << "VIEWING SPECIAL DEALS...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 8: // ADD MONEY
            displayHeader("ADD MONEY");
            cout << "1. ADD COINS\n";
            cout << "2. ADD NOTES\n";
            cout << "3. ADD CARD PAYMENT\n";
            cout << "4. ADD DIGITAL PAYMENT\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "ADDING COINS...\n"; break;
                case 2: cout << "ADDING NOTES...\n"; break;
                case 3: cout << "ADDING CARD PAYMENT...\n"; break;
                case 4: cout << "ADDING DIGITAL PAYMENT...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
            
        case 9: // VIEW BALANCE
            displayHeader("VIEW BALANCE");
            cout << "1. VIEW CURRENT BALANCE\n";
            cout << "2. VIEW TRANSACTION HISTORY\n";
            cout << "3. VIEW CHANGE DUE\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "VIEWING CURRENT BALANCE...\n"; break;
                case 2: cout << "VIEWING TRANSACTION HISTORY...\n"; break;
                case 3: cout << "VIEWING CHANGE DUE...\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            break;
    }
}
