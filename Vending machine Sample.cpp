#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    // Variable declarations
    int mainchoice, adminchoice, customerchoice, password;  // For storing user choices and password
    char repeat;  // For repeating the main menu
    
    do {
        // Display main menu
        system("cls"); // Clear screen command (for Windows)
        cout << setfill('=') << setw(50) << "" << endl;  // Top border
        cout << setfill(' ') << setw(35) << "MAIN MENU" << endl;  // Center-aligned title
        cout << setfill('=') << setw(50) << "" << endl;  // Bottom border
        cout << "1. CUSTOMER MENU" << endl;  // Option 1: Customer interface
        cout << "2. ADMIN MENU" << endl;     // Option 2: Admin interface  
        cout << "3. EXIT" << endl;           // Option 3: Exit program
        cout << setfill('=') << setw(50) << "" << endl;  // Menu bottom border
        cout << "Enter your choice (1-3): ";  // Prompt for input
        cin >> mainchoice;  // Store user's main choice
        
        // Main menu switch case
        switch(mainchoice)
        {
            case 1: // Customer Menu - Option 1 from main menu
                do {
                    system("cls");  // Clear screen for customer menu
                    cout << setfill('=') << setw(50) << "" << endl;
                    cout << setfill(' ') << setw(35) << "CUSTOMER MENU" << endl;
                    cout << setfill('=') << setw(50) << "" << endl;
                    cout << "1. View Products" << endl;     // See available products
                    cout << "2. Buy Products" << endl;      // Purchase items
                    cout << "3. Insert Money" << endl;      // Add money to virtual wallet
                    cout << "4. Check Balance" << endl;     // View current balance
                    cout << "5. Back to Main Menu" << endl; // Return to main menu
                    cout << setfill('=') << setw(50) << "" << endl;
                    cout << "Enter your choice (1-5): ";  // Prompt for customer choice
                    cin >> customerchoice;  // Store customer's choice
                    
                    // Customer menu switch case
                    switch(customerchoice)
                    {
                        case 1: // View Products submenu
                            system("cls");  // Clear screen for products view
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << setfill(' ') << setw(35) << "VIEW PRODUCTS" << endl;
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "1. Beverages" << endl;   // Drink category
                            cout << "2. Snacks" << endl;      // Snack category
                            cout << "3. Chocolates" << endl;  // Chocolate category
                            cout << "4. Biscuits" << endl;    // Biscuit category
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Press 0 to go back: ";  // Navigation option
                            cin >> customerchoice;  // Get user input for navigation
                            break;  // Exit this case
                            
                        case 2: // Buy Products submenu
                            system("cls");  // Clear screen for buying interface
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << setfill(' ') << setw(35) << "BUY PRODUCTS" << endl;
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Select product to buy:" << endl;
                            cout << "1. Coke - $1.50" << endl;      // Product 1 with price
                            cout << "2. Chips - $2.00" << endl;     // Product 2 with price
                            cout << "3. Chocolate - $1.00" << endl; // Product 3 with price
                            cout << "4. Water - $1.00" << endl;     // Product 4 with price
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Press 0 to go back: ";  // Navigation option
                            cin >> customerchoice;  // Get user selection
                            break;  // Exit this case
                            
                        case 3: // Insert Money submenu
                            system("cls");  // Clear screen for money insertion
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << setfill(' ') << setw(35) << "INSERT MONEY" << endl;
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "1. Insert $1" << endl;         // Insert $1
                            cout << "2. Insert $5" << endl;         // Insert $5
                            cout << "3. Insert $10" << endl;        // Insert $10
                            cout << "4. Custom amount" << endl;     // Insert any amount
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Press 0 to go back: ";  // Navigation option
                            cin >> customerchoice;  // Get user selection
                            break;  // Exit this case
                            
                        case 4: // Check Balance display
                            system("cls");  // Clear screen for balance display
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << setfill(' ') << setw(35) << "CHECK BALANCE" << endl;
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Your current balance: $0.00" << endl;  // Display balance
                            cout << setfill('=') << setw(50) << "" << endl;
                            cout << "Press 0 to go back: ";  // Navigation option
                            cin >> customerchoice;  // Get user input
                            break;  // Exit this case
                            
                        case 5: // Return to main menu
                            cout << "Returning to main menu..." << endl;  // Exit message
                            break;  // Exit this case
                            
                        default: // Invalid input handler
                            cout << "Invalid choice! Press 0 to go back: ";  // Error message
                            cin >> customerchoice;  // Get user input to continue
                    }
                } while(customerchoice != 5);  // Loop until user chooses option 5 (Back)
                break;  // Exit customer menu case
                
            case 2: // Admin Menu - Option 2 from main menu
                system("cls");  // Clear screen for password entry
                cout << "Enter admin password (password is 1234): ";  // Password prompt
                cin >> password;  // Get password input
                
                if(password == 1234)  // Check if password is correct
                {
                    do {
                        system("cls");  // Clear screen for admin menu
                        cout << setfill('=') << setw(50) << "" << endl;
                        cout << setfill(' ') << setw(35) << "ADMIN MENU" << endl;
                        cout << setfill('=') << setw(50) << "" << endl;
                        cout << "1. Manage Products" << endl;     // Product management
                        cout << "2. View Sales Report" << endl;   // Sales analytics
                        cout << "3. Manage Inventory" << endl;    // Stock management
                        cout << "4. System Settings" << endl;     // System configuration
                        cout << "5. Back to Main Menu" << endl;   // Return to main
                        cout << setfill('=') << setw(50) << "" << endl;
                        cout << "Enter your choice (1-5): ";  // Prompt for admin choice
                        cin >> adminchoice;  // Store admin's choice
                        
                        // Admin menu switch case
                        switch(adminchoice)
                        {
                            case 1: // Manage Products submenu
                                system("cls");  // Clear screen for product management
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << setfill(' ') << setw(35) << "MANAGE PRODUCTS" << endl;
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "1. Add New Product" << endl;        // Add products
                                cout << "2. Remove Product" << endl;         // Delete products
                                cout << "3. Update Product Price" << endl;   // Modify prices
                                cout << "4. View All Products" << endl;      // List all products
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "Press 0 to go back: ";  // Navigation option
                                cin >> adminchoice;  // Get admin input
                                break;  // Exit this case
                                
                            case 2: // Sales Report submenu
                                system("cls");  // Clear screen for sales report
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << setfill(' ') << setw(35) << "SALES REPORT" << endl;
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "1. Daily Sales" << endl;    // Today's sales
                                cout << "2. Weekly Sales" << endl;   // This week's sales
                                cout << "3. Monthly Sales" << endl;  // This month's sales
                                cout << "4. Yearly Sales" << endl;   // This year's sales
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "Press 0 to go back: ";  // Navigation option
                                cin >> adminchoice;  // Get admin input
                                break;  // Exit this case
                                
                            case 3: // Manage Inventory submenu
                                system("cls");  // Clear screen for inventory management
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << setfill(' ') << setw(35) << "MANAGE INVENTORY" << endl;
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "1. Check Stock" << endl;           // Current stock levels
                                cout << "2. Restock Items" << endl;         // Add inventory
                                cout << "3. View Low Stock Items" << endl;  // Items needing restock
                                cout << "4. Inventory Report" << endl;      // Complete inventory report
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "Press 0 to go back: ";  // Navigation option
                                cin >> adminchoice;  // Get admin input
                                break;  // Exit this case
                                
                            case 4: // System Settings submenu
                                system("cls");  // Clear screen for system settings
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << setfill(' ') << setw(35) << "SYSTEM SETTINGS" << endl;
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "1. Change Password" << endl;     // Update admin password
                                cout << "2. System Information" << endl;  // View system details
                                cout << "3. Backup Data" << endl;         // Create data backup
                                cout << "4. Reset System" << endl;        // Factory reset
                                cout << setfill('=') << setw(50) << "" << endl;
                                cout << "Press 0 to go back: ";  // Navigation option
                                cin >> adminchoice;  // Get admin input
                                break;  // Exit this case
                                
                            case 5: // Return to main menu
                                cout << "Returning to main menu..." << endl;  // Exit message
                                break;  // Exit this case
                                
                            default: // Invalid input handler
                                cout << "Invalid choice! Press 0 to go back: ";  // Error message
                                cin >> adminchoice;  // Get admin input to continue
                        }
                    } while(adminchoice != 5);  // Loop until admin chooses option 5 (Back)
                }
                else  // Incorrect password
                {
                    cout << "Incorrect password! Access denied." << endl;  // Error message
                    cout << "Press any key to continue...";  // Wait for user
                    cin.ignore();  // Clear input buffer
                    cin.get();     // Wait for key press
                }
                break;  // Exit admin menu case
                
            case 3: // Exit Program - Option 3 from main menu
                system("cls");  // Clear screen for exit message
                cout << setfill('=') << setw(50) << "" << endl;
                cout << setfill(' ') << setw(35) << "THANK YOU!" << endl;     // Thank you message
                cout << setfill(' ') << setw(35) << "GOODBYE!" << endl;      // Goodbye message
                cout << setfill('=') << setw(50) << "" << endl;
                return 0;  // Exit program successfully
                
            default: // Invalid main menu input
                cout << "Invalid choice! Please try again." << endl;  // Error message
        }
        
        // Ask user if they want to return to main menu
        cout << "\nDo you want to continue? (y/n): ";  // Continue prompt
        cin >> repeat;  // Get user's response
        
    } while(repeat == 'y' || repeat == 'Y');  // Loop if user wants to continue
    
    // Final exit message (if user chooses not to continue)
    system("cls");  // Clear screen
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ') << setw(35) << "THANK YOU FOR USING!" << endl;  // Final thank you
    cout << setfill('=') << setw(50) << "" << endl;
    
    return 0;  // Exit program successfully
}
