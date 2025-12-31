#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// ========================
// STRUCT DEFINITIONS
// ========================
struct Item {
    int code;           // Item code
    string name;        // Item name
    string category;    // Category (Drinks/Snacks/Chocolates/Biscuits)
    double price;       // Price
    int stock;          // Stock quantity
};

struct CartItem {
    int code;
    string name;
    double price;
    int quantity;
    double total;
};

// ========================
// GLOBAL VARIABLES
// ========================
const int MAX_ITEMS = 100;  // Maximum items our machine can hold
const int MAX_CART = 50;    // Maximum items in cart

Item inventory[MAX_ITEMS];  // Array to store all items
CartItem cart[MAX_CART];    // Array for shopping cart

int itemCount = 0;          // How many items we actually have
int cartCount = 0;          // How many items in cart
double customerBalance = 0; // Customer's money
double totalSales = 0;      // Total sales amount
int totalTransactions = 0;  // Number of transactions

// Admin password
const int ADMIN_PASSWORD = 8411;

// ========================
// FUNCTION DECLARATIONS
// ========================
void displayHeader(const string& title);
void displayAdminMenu();
void displayCustomerMenu();
void adminSubMenu(int choice);
void customerSubMenu(int choice);
void addSampleData();  // To add some sample items for testing

// Admin Functions
void addItemMenu();
void viewAllItemsMenu();
void searchItemMenu();
void updateItemMenu();
void deleteItemMenu();
void viewStockMenu();
void restockItemMenu();
void setPricesMenu();

// Customer Functions
void viewItemsCustomerMenu();
void searchItemCustomerMenu();
void purchaseItemMenu();
void viewCartMenu();
void checkoutMenu();
void viewPricesMenu();
void addMoneyMenu();
void viewBalanceMenu();

// Utility Functions
void addItem(int code, string name, string category, double price, int stock);
void displayItem(Item item);
int findItemByCode(int code);
int findItemByName(string name);
void clearScreen();
void pauseProgram();

// ========================
// MAIN FUNCTION
// ========================
int main() {
    int mainChoice, adminChoice, customerChoice, password;
    char repeat;
    int subMenuChoices[100];
    
    // Add some sample data for testing
    addSampleData();
    
    do {
        displayHeader("VENDING MACHINE SYSTEM");
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
                    
                    if(password == ADMIN_PASSWORD) {
                        cout << "ACCESS GRANTED\n";
                        pauseProgram();
                        
                        do {
                            displayAdminMenu();
                            cin >> adminChoice;
                            
                            if(adminChoice == 16) {
                                cout << "RETURNING TO MAIN MENU...\n";
                                pauseProgram();
                                break;
                            }
                            
                            if(adminChoice >= 1 && adminChoice <= 15) {
                                adminSubMenu(adminChoice);
                            } else {
                                cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-16)\n";
                                pauseProgram();
                            }
                        } while(adminChoice != 16);
                        break;
                    } else {
                        cout << "ACCESS DENIED! TRY AGAIN!\n";
                        pauseProgram();
                    }
                }
                break;
                
            case 2: // Customer Menu
                do {
                    displayCustomerMenu();
                    cin >> customerChoice;
                    
                    if(customerChoice == 10) {
                        cout << "RETURNING TO MAIN MENU...\n";
                        pauseProgram();
                        break;
                    }
                    
                    if(customerChoice >= 1 && customerChoice <= 9) {
                        customerSubMenu(customerChoice);
                    } else {
                        cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-10)\n";
                        pauseProgram();
                    }
                } while(customerChoice != 10);
                break;
                
            case 3: // Exit
                displayHeader("THANK YOU FOR USING VENDING MACHINE!");
                cout << "Total Sales: $" << totalSales << endl;
                cout << "Total Transactions: " << totalTransactions << endl;
                pauseProgram();
                return 0;
                
            default:
                cout << "INVALID OPTION! PLEASE SELECT OPTION BETWEEN (1-3)\n";
                pauseProgram();
        }
        
        cout << "\nReturn to MAIN MENU? (Y/N): ";
        cin >> repeat;
    } while(repeat == 'Y' || repeat == 'y');
    
    return 0;
}

// ========================
// DISPLAY FUNCTIONS
// ========================
void displayHeader(const string& title) {
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(25) << right << title << endl;
    cout << setfill('=') << setw(40) << "" << endl;
}

void displayAdminMenu() {
    clearScreen();
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

void displayCustomerMenu() {
    clearScreen();
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

// ========================
// ADMIN SUB-MENU FUNCTION
// ========================
void adminSubMenu(int choice) {
    int subChoice;
    
    switch(choice) {
        case 1: // ADD ITEM
            addItemMenu();
            break;
            
        case 2: // VIEW ALL ITEMS
            viewAllItemsMenu();
            break;
            
        case 3: // SEARCH ITEM
            searchItemMenu();
            break;
            
        case 4: // UPDATE ITEM
            updateItemMenu();
            break;
            
        case 5: // DELETE ITEM
            deleteItemMenu();
            break;
            
        case 6: // VIEW STOCK
            viewStockMenu();
            break;
            
        case 7: // RESTOCK ITEM
            restockItemMenu();
            break;
            
        case 8: // SET PRICES
            setPricesMenu();
            break;
            
        case 9: // VIEW SALES REPORT
            displayHeader("SALES REPORT");
            cout << "Total Sales: $" << fixed << setprecision(2) << totalSales << endl;
            cout << "Total Transactions: " << totalTransactions << endl;
            cout << "Items in Inventory: " << itemCount << endl;
            pauseProgram();
            break;
            
        case 10: // TRANSACTION HISTORY
            displayHeader("TRANSACTION HISTORY");
            cout << "Total Transactions: " << totalTransactions << endl;
            cout << "Total Revenue: $" << fixed << setprecision(2) << totalSales << endl;
            cout << "Average per Transaction: $" << (totalTransactions > 0 ? totalSales/totalTransactions : 0) << endl;
            pauseProgram();
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
                case 3: 
                    cout << "AVAILABLE CATEGORIES:\n";
                    cout << "1. Drinks\n2. Snacks\n3. Chocolates\n4. Biscuits\n";
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 12: // LOW STOCK ITEMS
            displayHeader("LOW STOCK ITEMS");
            cout << "Checking for items with low stock...\n\n";
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].stock <= 5) {  // Low stock if 5 or less
                    cout << "LOW STOCK: " << inventory[i].name 
                         << " (Code: " << inventory[i].code 
                         << ") - Only " << inventory[i].stock << " left!\n";
                }
            }
            if(itemCount == 0) {
                cout << "No items in inventory.\n";
            }
            pauseProgram();
            break;
            
        case 13: // GENERATE REPORTS
            displayHeader("GENERATE REPORTS");
            cout << "1. GENERATE SALES REPORT\n";
            cout << "2. GENERATE STOCK REPORT\n";
            cout << "3. GENERATE PROFIT REPORT\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: 
                    cout << "\n=== SALES REPORT ===\n";
                    cout << "Total Sales: $" << totalSales << endl;
                    cout << "Total Transactions: " << totalTransactions << endl;
                    break;
                case 2: 
                    cout << "\n=== STOCK REPORT ===\n";
                    cout << "Total Items: " << itemCount << endl;
                    cout << "Total Stock Value: Calculating...\n";
                    break;
                case 3: 
                    cout << "\n=== PROFIT REPORT ===\n";
                    cout << "Profit Calculation: (Assuming 30% profit margin)\n";
                    cout << "Estimated Profit: $" << totalSales * 0.3 << endl;
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 14: // MACHINE SETTINGS
            displayHeader("MACHINE SETTINGS");
            cout << "1. CHANGE PASSWORD\n";
            cout << "2. SET MAINTENANCE MODE\n";
            cout << "3. SYSTEM INFO\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: 
                    cout << "Enter new password (numbers only): ";
                    int newPass;
                    cin >> newPass;
                    // In real system, you'd update ADMIN_PASSWORD
                    cout << "Password changed successfully!\n";
                    break;
                case 2: cout << "MAINTENANCE MODE ACTIVATED\n"; break;
                case 3: 
                    cout << "=== SYSTEM INFORMATION ===\n";
                    cout << "Items in system: " << itemCount << endl;
                    cout << "Cart capacity: " << MAX_CART << endl;
                    cout << "Inventory capacity: " << MAX_ITEMS << endl;
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 15: // BACKUP DATA
            displayHeader("BACKUP DATA");
            cout << "1. BACKUP ALL DATA\n";
            cout << "2. RESTORE DATA\n";
            cout << "3. VIEW BACKUP FILES\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: cout << "BACKING UP ALL DATA...\nData saved successfully!\n"; break;
                case 2: cout << "RESTORING DATA...\nData restored successfully!\n"; break;
                case 3: cout << "VIEWING BACKUP FILES...\nbackup_2024.txt\nbackup_2023.txt\n"; break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
    }
}

// ========================
// CUSTOMER SUB-MENU FUNCTION
// ========================
void customerSubMenu(int choice) {
    int subChoice;
    
    switch(choice) {
        case 1: // VIEW ITEMS
            viewItemsCustomerMenu();
            break;
            
        case 2: // SEARCH ITEM
            searchItemCustomerMenu();
            break;
            
        case 3: // PURCHASE ITEM
            purchaseItemMenu();
            break;
            
        case 4: // VIEW CART
            viewCartMenu();
            break;
            
        case 5: // CHECKOUT
            checkoutMenu();
            break;
            
        case 6: // VIEW PRICES
            viewPricesMenu();
            break;
            
        case 7: // VIEW OFFERS
            displayHeader("VIEW OFFERS");
            cout << "1. VIEW CURRENT OFFERS\n";
            cout << "2. VIEW DISCOUNT CODES\n";
            cout << "3. VIEW SPECIAL DEALS\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: 
                    cout << "\n=== CURRENT OFFERS ===\n";
                    cout << "1. Buy 2 Chocolates, get 10% off!\n";
                    cout << "2. Free biscuit with any drink purchase!\n";
                    break;
                case 2: 
                    cout << "\n=== DISCOUNT CODES ===\n";
                    cout << "SAVE10 - Get 10% off\n";
                    cout << "WELCOME5 - Get $5 off first purchase\n";
                    break;
                case 3: 
                    cout << "\n=== SPECIAL DEALS ===\n";
                    cout << "Combo Deal: Drink + Snack = $3.99\n";
                    cout << "Family Pack: 4 items for price of 3\n";
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 8: // ADD MONEY
            addMoneyMenu();
            break;
            
        case 9: // VIEW BALANCE
            viewBalanceMenu();
            break;
    }
}

// ========================
// ADMIN FUNCTION IMPLEMENTATIONS
// ========================
void addItemMenu() {
    int code;
    string name, category;
    double price;
    int stock, categoryChoice;
    
    displayHeader("ADD ITEM");
    cout << "1. ADD DRINKS\n";
    cout << "2. ADD SNACKS\n";
    cout << "3. ADD CHOCOLATES\n";
    cout << "4. ADD BISCUITS\n";
    displayHeader("SELECT OPTION");
    cin >> categoryChoice;
    
    // Map choice to category
    switch(categoryChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        case 4: category = "Biscuits"; break;
        default: 
            cout << "Invalid category!\n";
            pauseProgram();
            return;
    }
    
    cout << "\nEnter item code (100-999): ";
    cin >> code;
    
    // Check if code already exists
    if(findItemByCode(code) != -1) {
        cout << "Item with this code already exists!\n";
        pauseProgram();
        return;
    }
    
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter price: $";
    cin >> price;
    
    cout << "Enter initial stock: ";
    cin >> stock;
    
    // Add item to inventory
    addItem(code, name, category, price, stock);
    cout << "\nItem added successfully!\n";
    pauseProgram();
}

void viewAllItemsMenu() {
    displayHeader("VIEW ALL ITEMS");
    cout << "1. VIEW BY CATEGORY\n";
    cout << "2. VIEW BY PRICE\n";
    cout << "3. VIEW BY STOCK\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: 
            cout << "\n=== ITEMS BY CATEGORY ===\n";
            // Display by category
            for(int i = 0; i < itemCount; i++) {
                cout << inventory[i].category << ": " 
                     << inventory[i].name << " ($" 
                     << inventory[i].price << ")\n";
            }
            break;
        case 2:
            cout << "\n=== ITEMS BY PRICE ===\n";
            // Simple bubble sort by price
            for(int i = 0; i < itemCount-1; i++) {
                for(int j = 0; j < itemCount-i-1; j++) {
                    if(inventory[j].price > inventory[j+1].price) {
                        Item temp = inventory[j];
                        inventory[j] = inventory[j+1];
                        inventory[j+1] = temp;
                    }
                }
            }
            // Display sorted items
            for(int i = 0; i < itemCount; i++) {
                displayItem(inventory[i]);
            }
            break;
        case 3:
            cout << "\n=== ITEMS BY STOCK ===\n";
            // Sort by stock
            for(int i = 0; i < itemCount-1; i++) {
                for(int j = 0; j < itemCount-i-1; j++) {
                    if(inventory[j].stock > inventory[j+1].stock) {
                        Item temp = inventory[j];
                        inventory[j] = inventory[j+1];
                        inventory[j+1] = temp;
                    }
                }
            }
            // Display sorted items
            for(int i = 0; i < itemCount; i++) {
                displayItem(inventory[i]);
            }
            break;
        default: 
            cout << "INVALID OPTION!\n";
    }
    
    if(itemCount == 0) {
        cout << "No items in inventory.\n";
    }
    pauseProgram();
}

void searchItemMenu() {
    displayHeader("SEARCH ITEM");
    cout << "1. SEARCH BY NAME\n";
    cout << "2. SEARCH BY CODE\n";
    cout << "3. SEARCH BY CATEGORY\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: {
            string searchName;
            cout << "Enter item name to search: ";
            cin.ignore();
            getline(cin, searchName);
            
            bool found = false;
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].name.find(searchName) != string::npos) {
                    displayItem(inventory[i]);
                    found = true;
                }
            }
            if(!found) cout << "No items found with that name.\n";
            break;
        }
        case 2: {
            int searchCode;
            cout << "Enter item code to search: ";
            cin >> searchCode;
            
            int index = findItemByCode(searchCode);
            if(index != -1) {
                displayItem(inventory[index]);
            } else {
                cout << "Item not found.\n";
            }
            break;
        }
        case 3: {
            string searchCategory;
            cout << "Enter category to search: ";
            cin.ignore();
            getline(cin, searchCategory);
            
            bool found = false;
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == searchCategory) {
                    displayItem(inventory[i]);
                    found = true;
                }
            }
            if(!found) cout << "No items found in that category.\n";
            break;
        }
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void updateItemMenu() {
    displayHeader("UPDATE ITEM");
    cout << "1. UPDATE PRICE\n";
    cout << "2. UPDATE STOCK\n";
    cout << "3. UPDATE DETAILS\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    int code;
    cout << "Enter item code to update: ";
    cin >> code;
    
    int index = findItemByCode(code);
    if(index == -1) {
        cout << "Item not found.\n";
        pauseProgram();
        return;
    }
    
    switch(subChoice) {
        case 1:
            cout << "Current price: $" << inventory[index].price << endl;
            cout << "Enter new price: $";
            cin >> inventory[index].price;
            cout << "Price updated successfully!\n";
            break;
        case 2:
            cout << "Current stock: " << inventory[index].stock << endl;
            cout << "Enter new stock: ";
            cin >> inventory[index].stock;
            cout << "Stock updated successfully!\n";
            break;
        case 3:
            cout << "Current name: " << inventory[index].name << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, inventory[index].name);
            cout << "Name updated successfully!\n";
            break;
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void deleteItemMenu() {
    displayHeader("DELETE ITEM");
    cout << "1. DELETE BY CODE\n";
    cout << "2. DELETE BY NAME\n";
    cout << "3. DELETE BY CATEGORY\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: {
            int code;
            cout << "Enter item code to delete: ";
            cin >> code;
            
            int index = findItemByCode(code);
            if(index != -1) {
                // Shift all items after this one
                for(int i = index; i < itemCount - 1; i++) {
                    inventory[i] = inventory[i + 1];
                }
                itemCount--;
                cout << "Item deleted successfully!\n";
            } else {
                cout << "Item not found.\n";
            }
            break;
        }
        case 2: {
            string name;
            cout << "Enter item name to delete: ";
            cin.ignore();
            getline(cin, name);
            
            int index = findItemByName(name);
            if(index != -1) {
                for(int i = index; i < itemCount - 1; i++) {
                    inventory[i] = inventory[i + 1];
                }
                itemCount--;
                cout << "Item deleted successfully!\n";
            } else {
                cout << "Item not found.\n";
            }
            break;
        }
        case 3: {
            string category;
            cout << "Enter category to delete: ";
            cin.ignore();
            getline(cin, category);
            
            int deleted = 0;
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == category) {
                    // Shift items
                    for(int j = i; j < itemCount - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }
                    itemCount--;
                    i--; // Check same index again
                    deleted++;
                }
            }
            cout << deleted << " items deleted from category: " << category << endl;
            break;
        }
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void viewStockMenu() {
    displayHeader("VIEW STOCK");
    cout << "1. VIEW DRINKS STOCK\n";
    cout << "2. VIEW SNACKS STOCK\n";
    cout << "3. VIEW CHOCOLATES STOCK\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    string category;
    switch(subChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        default: 
            cout << "INVALID OPTION!\n";
            pauseProgram();
            return;
    }
    
    cout << "\n=== " << category << " STOCK ===\n";
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category) {
            cout << inventory[i].name << ": " << inventory[i].stock << " units\n";
            found = true;
        }
    }
    if(!found) cout << "No items in this category.\n";
    pauseProgram();
}

void restockItemMenu() {
    displayHeader("RESTOCK ITEM");
    cout << "1. RESTOCK DRINKS\n";
    cout << "2. RESTOCK SNACKS\n";
    cout << "3. RESTOCK CHOCOLATES\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    string category;
    switch(subChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        default: 
            cout << "INVALID OPTION!\n";
            pauseProgram();
            return;
    }
    
    cout << "\n=== RESTOCK " << category << " ===\n";
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category) {
            cout << inventory[i].name << " (Code: " << inventory[i].code 
                 << ") - Current stock: " << inventory[i].stock << endl;
            cout << "Add how many units? ";
            int addUnits;
            cin >> addUnits;
            inventory[i].stock += addUnits;
            cout << "Stock updated to: " << inventory[i].stock << endl;
            found = true;
        }
    }
    if(!found) cout << "No items in this category.\n";
    pauseProgram();
}

void setPricesMenu() {
    displayHeader("SET PRICES");
    cout << "1. SET DRINKS PRICES\n";
    cout << "2. SET SNACKS PRICES\n";
    cout << "3. SET CHOCOLATES PRICES\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    string category;
    switch(subChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        default: 
            cout << "INVALID OPTION!\n";
            pauseProgram();
            return;
    }
    
    cout << "\n=== SET " << category << " PRICES ===\n";
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category) {
            cout << inventory[i].name << " (Code: " << inventory[i].code 
                 << ") - Current price: $" << inventory[i].price << endl;
            cout << "Enter new price: $";
            cin >> inventory[i].price;
            cout << "Price updated successfully!\n";
            found = true;
        }
    }
    if(!found) cout << "No items in this category.\n";
    pauseProgram();
}

// ========================
// CUSTOMER FUNCTION IMPLEMENTATIONS
// ========================
void viewItemsCustomerMenu() {
    displayHeader("VIEW ITEMS");
    cout << "1. VIEW DRINKS\n";
    cout << "2. VIEW SNACKS\n";
    cout << "3. VIEW CHOCOLATES\n";
    cout << "4. VIEW ALL ITEMS\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: 
            cout << "\n=== DRINKS ===\n";
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == "Drinks") {
                    displayItem(inventory[i]);
                }
            }
            break;
        case 2:
            cout << "\n=== SNACKS ===\n";
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == "Snacks") {
                    displayItem(inventory[i]);
                }
            }
            break;
        case 3:
            cout << "\n=== CHOCOLATES ===\n";
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == "Chocolates") {
                    displayItem(inventory[i]);
                }
            }
            break;
        case 4:
            cout << "\n=== ALL ITEMS ===\n";
            for(int i = 0; i < itemCount; i++) {
                displayItem(inventory[i]);
            }
            break;
        default: 
            cout << "INVALID OPTION!\n";
    }
    
    if(itemCount == 0) {
        cout << "No items available.\n";
    }
    pauseProgram();
}

void searchItemCustomerMenu() {
    displayHeader("SEARCH ITEM");
    cout << "1. SEARCH BY NAME\n";
    cout << "2. SEARCH BY CODE\n";
    cout << "3. SEARCH BY CATEGORY\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: {
            string searchName;
            cout << "Enter item name to search: ";
            cin.ignore();
            getline(cin, searchName);
            
            bool found = false;
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].name.find(searchName) != string::npos) {
                    displayItem(inventory[i]);
                    found = true;
                }
            }
            if(!found) cout << "No items found with that name.\n";
            break;
        }
        case 2: {
            int searchCode;
            cout << "Enter item code to search: ";
            cin >> searchCode;
            
            int index = findItemByCode(searchCode);
            if(index != -1) {
                displayItem(inventory[index]);
            } else {
                cout << "Item not found.\n";
            }
            break;
        }
        case 3: {
            string searchCategory;
            cout << "Enter category to search: ";
            cin.ignore();
            getline(cin, searchCategory);
            
            bool found = false;
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].category == searchCategory) {
                    displayItem(inventory[i]);
                    found = true;
                }
            }
            if(!found) cout << "No items found in that category.\n";
            break;
        }
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void purchaseItemMenu() {
    displayHeader("PURCHASE ITEM");
    cout << "1. BUY DRINKS\n";
    cout << "2. BUY SNACKS\n";
    cout << "3. BUY CHOCOLATES\n";
    cout << "4. BUY BISCUITS\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    string category;
    switch(subChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        case 4: category = "Biscuits"; break;
        default: 
            cout << "INVALID OPTION!\n";
            pauseProgram();
            return;
    }
    
    // Show items in this category
    cout << "\n=== AVAILABLE " << category << " ===\n";
    int availableItems[MAX_ITEMS];
    int availableCount = 0;
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category && inventory[i].stock > 0) {
            cout << availableCount + 1 << ". ";
            displayItem(inventory[i]);
            availableItems[availableCount] = i;
            availableCount++;
        }
    }
    
    if(availableCount == 0) {
        cout << "No items available in this category.\n";
        pauseProgram();
        return;
    }
    
    cout << "\nEnter item number to purchase (1-" << availableCount << "): ";
    int itemChoice;
    cin >> itemChoice;
    
    if(itemChoice < 1 || itemChoice > availableCount) {
        cout << "Invalid choice!\n";
        pauseProgram();
        return;
    }
    
    int itemIndex = availableItems[itemChoice - 1];
    
    cout << "Enter quantity: ";
    int quantity;
    cin >> quantity;
    
    if(quantity <= 0) {
        cout << "Quantity must be positive!\n";
        pauseProgram();
        return;
    }
    
    if(quantity > inventory[itemIndex].stock) {
        cout << "Not enough stock! Only " << inventory[itemIndex].stock << " available.\n";
        pauseProgram();
        return;
    }
    
    // Add to cart
    if(cartCount < MAX_CART) {
        cart[cartCount].code = inventory[itemIndex].code;
        cart[cartCount].name = inventory[itemIndex].name;
        cart[cartCount].price = inventory[itemIndex].price;
        cart[cartCount].quantity = quantity;
        cart[cartCount].total = inventory[itemIndex].price * quantity;
        cartCount++;
        
        cout << "\nAdded to cart: " << quantity << " x " << inventory[itemIndex].name 
             << " = $" << cart[cartCount-1].total << endl;
    } else {
        cout << "Cart is full!\n";
    }
    pauseProgram();
}

void viewCartMenu() {
    displayHeader("VIEW CART");
    cout << "1. VIEW CART ITEMS\n";
    cout << "2. REMOVE FROM CART\n";
    cout << "3. CLEAR CART\n";
    cout << "4. UPDATE QUANTITY\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: 
            cout << "\n=== CART ITEMS ===\n";
            if(cartCount == 0) {
                cout << "Cart is empty.\n";
            } else {
                double cartTotal = 0;
                for(int i = 0; i < cartCount; i++) {
                    cout << i+1 << ". " << cart[i].name 
                         << " (x" << cart[i].quantity 
                         << ") - $" << cart[i].total << endl;
                    cartTotal += cart[i].total;
                }
                cout << "\nTOTAL: $" << cartTotal << endl;
            }
            break;
            
        case 2: 
            if(cartCount == 0) {
                cout << "Cart is empty.\n";
            } else {
                cout << "Enter item number to remove (1-" << cartCount << "): ";
                int removeChoice;
                cin >> removeChoice;
                
                if(removeChoice >= 1 && removeChoice <= cartCount) {
                    cout << "Removed: " << cart[removeChoice-1].name << endl;
                    // Shift items
                    for(int i = removeChoice-1; i < cartCount-1; i++) {
                        cart[i] = cart[i+1];
                    }
                    cartCount--;
                } else {
                    cout << "Invalid choice!\n";
                }
            }
            break;
            
        case 3: 
            cartCount = 0;
            cout << "Cart cleared!\n";
            break;
            
        case 4: 
            if(cartCount == 0) {
                cout << "Cart is empty.\n";
            } else {
                cout << "Enter item number to update (1-" << cartCount << "): ";
                int updateChoice;
                cin >> updateChoice;
                
                if(updateChoice >= 1 && updateChoice <= cartCount) {
                    cout << "Current quantity: " << cart[updateChoice-1].quantity << endl;
                    cout << "Enter new quantity: ";
                    int newQty;
                    cin >> newQty;
                    
                    // Find the item in inventory to check stock
                    int invIndex = findItemByCode(cart[updateChoice-1].code);
                    if(invIndex != -1 && newQty <= inventory[invIndex].stock) {
                        cart[updateChoice-1].quantity = newQty;
                        cart[updateChoice-1].total = cart[updateChoice-1].price * newQty;
                        cout << "Quantity updated!\n";
                    } else {
                        cout << "Not enough stock or invalid quantity!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
            }
            break;
            
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void checkoutMenu() {
    displayHeader("CHECKOUT");
    cout << "1. PROCEED TO PAYMENT\n";
    cout << "2. VIEW BILL\n";
    cout << "3. APPLY DISCOUNT\n";
    cout << "4. CANCEL ORDER\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: 
            if(cartCount == 0) {
                cout << "Cart is empty!\n";
            } else {
                // Calculate total
                double cartTotal = 0;
                for(int i = 0; i < cartCount; i++) {
                    cartTotal += cart[i].total;
                }
                
                cout << "\nTotal amount: $" << cartTotal << endl;
                cout << "Your balance: $" << customerBalance << endl;
                
                if(customerBalance >= cartTotal) {
                    // Process payment
                    customerBalance -= cartTotal;
                    totalSales += cartTotal;
                    totalTransactions++;
                    
                    // Update inventory stock
                    for(int i = 0; i < cartCount; i++) {
                        int invIndex = findItemByCode(cart[i].code);
                        if(invIndex != -1) {
                            inventory[invIndex].stock -= cart[i].quantity;
                        }
                    }
                    
                    cout << "\n=== RECEIPT ===\n";
                    cout << "Items purchased:\n";
                    for(int i = 0; i < cartCount; i++) {
                        cout << "- " << cart[i].name << " x" << cart[i].quantity 
                             << " @ $" << cart[i].price << " = $" << cart[i].total << endl;
                    }
                    cout << "Total: $" << cartTotal << endl;
                    cout << "Remaining balance: $" << customerBalance << endl;
                    cout << "Thank you for your purchase!\n";
                    
                    // Clear cart
                    cartCount = 0;
                } else {
                    cout << "Insufficient balance! Please add more money.\n";
                }
            }
            break;
            
        case 2: 
            cout << "\n=== CURRENT BILL ===\n";
            if(cartCount == 0) {
                cout << "Cart is empty.\n";
            } else {
                double cartTotal = 0;
                for(int i = 0; i < cartCount; i++) {
                    cout << cart[i].name << " x" << cart[i].quantity 
                         << " @ $" << cart[i].price << " = $" << cart[i].total << endl;
                    cartTotal += cart[i].total;
                }
                cout << "SUBTOTAL: $" << cartTotal << endl;
            }
            break;
            
        case 3: 
            cout << "Enter discount code: ";
            string discountCode;
            cin >> discountCode;
            
            if(discountCode == "SAVE10") {
                cout << "10% discount applied!\n";
            } else if(discountCode == "WELCOME5") {
                cout << "$5 discount applied!\n";
            } else {
                cout << "Invalid discount code.\n";
            }
            break;
            
        case 4: 
            cartCount = 0;
            cout << "Order cancelled. Cart cleared.\n";
            break;
            
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void viewPricesMenu() {
    displayHeader("VIEW PRICES");
    cout << "1. VIEW DRINKS PRICES\n";
    cout << "2. VIEW SNACKS PRICES\n";
    cout << "3. VIEW CHOCOLATES PRICES\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    string category;
    switch(subChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        default: 
            cout << "INVALID OPTION!\n";
            pauseProgram();
            return;
    }
    
    cout << "\n=== " << category << " PRICES ===\n";
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category) {
            cout << inventory[i].name << ": $" << inventory[i].price << endl;
            found = true;
        }
    }
    if(!found) cout << "No items in this category.\n";
    pauseProgram();
}

void addMoneyMenu() {
    displayHeader("ADD MONEY");
    cout << "1. ADD COINS\n";
    cout << "2. ADD NOTES\n";
    cout << "3. ADD CARD PAYMENT\n";
    cout << "4. ADD DIGITAL PAYMENT\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    double amount;
    switch(subChoice) {
        case 1: 
            cout << "Enter amount to add (coins): $";
            cin >> amount;
            if(amount > 0) {
                customerBalance += amount;
                cout << "Added $" << amount << " in coins.\n";
            }
            break;
        case 2:
            cout << "Enter amount to add (notes): $";
            cin >> amount;
            if(amount > 0) {
                customerBalance += amount;
                cout << "Added $" << amount << " in notes.\n";
            }
            break;
        case 3:
            cout << "Enter card payment amount: $";
            cin >> amount;
            if(amount > 0) {
                customerBalance += amount;
                cout << "Card payment of $" << amount << " processed.\n";
            }
            break;
        case 4:
            cout << "Enter digital payment amount: $";
            cin >> amount;
            if(amount > 0) {
                customerBalance += amount;
                cout << "Digital payment of $" << amount << " processed.\n";
            }
            break;
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

void viewBalanceMenu() {
    displayHeader("VIEW BALANCE");
    cout << "1. VIEW CURRENT BALANCE\n";
    cout << "2. VIEW TRANSACTION HISTORY\n";
    cout << "3. VIEW CHANGE DUE\n";
    displayHeader("SELECT OPTION");
    
    int subChoice;
    cin >> subChoice;
    
    switch(subChoice) {
        case 1: 
            cout << "\nCurrent Balance: $" << customerBalance << endl;
            break;
        case 2:
            cout << "\n=== TRANSACTION HISTORY ===\n";
            cout << "Total purchases: " << totalTransactions << endl;
            cout << "Total spent: $" << totalSales << endl;
            break;
        case 3:
            cout << "\n=== CHANGE DUE ===\n";
            // Calculate cart total for potential change
            double cartTotal = 0;
            for(int i = 0; i < cartCount; i++) {
                cartTotal += cart[i].total;
            }
            if(customerBalance >= cartTotal) {
                cout << "If you purchase now, change due: $" 
                     << (customerBalance - cartTotal) << endl;
            } else {
                cout << "No change due (insufficient balance for purchase).\n";
            }
            break;
        default: 
            cout << "INVALID OPTION!\n";
    }
    pauseProgram();
}

// ========================
// UTILITY FUNCTIONS
// ========================
void addSampleData() {
    // Add some sample items for testing
    addItem(101, "Coca-Cola", "Drinks", 1.50, 10);
    addItem(102, "Pepsi", "Drinks", 1.50, 8);
    addItem(103, "Water", "Drinks", 1.00, 15);
    addItem(201, "Chips", "Snacks", 2.00, 12);
    addItem(202, "Cookies", "Snacks", 1.75, 6);
    addItem(301, "Chocolate Bar", "Chocolates", 1.25, 20);
    addItem(302, "Candy", "Chocolates", 0.75, 25);
    addItem(401, "Biscuits", "Biscuits", 1.50, 10);
}

void addItem(int code, string name, string category, double price, int stock) {
    if(itemCount < MAX_ITEMS) {
        inventory[itemCount].code = code;
        inventory[itemCount].name = name;
        inventory[itemCount].category = category;
        inventory[itemCount].price = price;
        inventory[itemCount].stock = stock;
        itemCount++;
    }
}

void displayItem(Item item) {
    cout << "Code: " << item.code 
         << " | Name: " << setw(15) << left << item.name 
         << " | Category: " << setw(10) << item.category
         << " | Price: $" << fixed << setprecision(2) << item.price
         << " | Stock: " << item.stock << endl;
}

int findItemByCode(int code) {
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            return i;
        }
    }
    return -1; // Not found
}

int findItemByName(string name) {
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].name == name) {
            return i;
        }
    }
    return -1; // Not found
}

void clearScreen() {
    // Simple clear screen - works on most systems
    system("cls||clear");
}

void pauseProgram() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
