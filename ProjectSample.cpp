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
    string category;    // Category
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
const int MAX_ITEMS = 100;  // Maximum items
const int MAX_CART = 50;    // Maximum cart items

Item inventory[MAX_ITEMS];  // Array for items
CartItem cart[MAX_CART];    // Array for cart

int itemCount = 0;          // Current items in inventory
int cartCount = 0;          // Current items in cart
double customerBalance = 0.0; 
double totalSales = 0.0;    
int totalTransactions = 0;  

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
void addSampleData();

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
bool itemCodeExists(int code);  // Changed from findItemByCode
bool itemNameExists(string name); // Changed from findItemByName
void clearScreen();
void pauseProgram();

// ========================
// MAIN FUNCTION
// ========================
int main() {
    int mainChoice, adminChoice, customerChoice, password;
    char repeat;
    
    // Add sample data
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
                displayHeader("THANK YOU!");
                cout << "Total Sales: $" << fixed << setprecision(2) << totalSales << endl;
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
            cout << fixed << setprecision(2);
            cout << "Total Sales: $" << totalSales << endl;
            cout << "Total Transactions: " << totalTransactions << endl;
            cout << "Items in Inventory: " << itemCount << endl;
            pauseProgram();
            break;
            
        case 10: // TRANSACTION HISTORY
            displayHeader("TRANSACTION HISTORY");
            cout << "Total Transactions: " << totalTransactions << endl;
            cout << "Total Revenue: $" << fixed << setprecision(2) << totalSales << endl;
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
            cout << "Items with low stock (5 or less):\n";
            for(int i = 0; i < itemCount; i++) {
                if(inventory[i].stock <= 5) {
                    cout << "- " << inventory[i].name << ": " << inventory[i].stock << " left\n";
                }
            }
            pauseProgram();
            break;
            
        case 13: // GENERATE REPORTS
            displayHeader("GENERATE REPORTS");
            cout << "1. SALES REPORT\n";
            cout << "2. STOCK REPORT\n";
            cout << "3. PROFIT REPORT\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: 
                    cout << "\nSALES REPORT\n";
                    cout << "Total Sales: $" << totalSales << endl;
                    cout << "Transactions: " << totalTransactions << endl;
                    break;
                case 2: 
                    cout << "\nSTOCK REPORT\n";
                    cout << "Total Items: " << itemCount << endl;
                    break;
                case 3: 
                    cout << "\nPROFIT REPORT\n";
                    cout << "Estimated Profit: $" << totalSales * 0.3 << endl;
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 14: // MACHINE SETTINGS
            displayHeader("MACHINE SETTINGS");
            cout << "1. CHANGE PASSWORD\n";
            cout << "2. MAINTENANCE MODE\n";
            cout << "3. SYSTEM INFO\n";
            displayHeader("SELECT OPTION");
            cin >> subChoice;
            
            switch(subChoice) {
                case 1: 
                    cout << "Password changed successfully!\n";
                    break;
                case 2: 
                    cout << "Maintenance mode activated!\n";
                    break;
                case 3: 
                    cout << "System Information:\n";
                    cout << "Items: " << itemCount << endl;
                    cout << "Cart size: " << MAX_CART << endl;
                    break;
                default: cout << "INVALID OPTION!\n";
            }
            pauseProgram();
            break;
            
        case 15: // BACKUP DATA
            displayHeader("BACKUP DATA");
            cout << "Data backed up successfully!\n";
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
            cout << "Special Offers:\n";
            cout << "1. Buy 1 get 1 free on selected items\n";
            cout << "2. 10% discount on all chocolates\n";
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
    
    switch(categoryChoice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        case 4: category = "Biscuits"; break;
        default: 
            cout << "Invalid choice!\n";
            pauseProgram();
            return;
    }
    
    cout << "\nEnter item code: ";
    cin >> code;
    
    // Check if code exists
    if(itemCodeExists(code)) {
        cout << "Item with this code already exists!\n";
        pauseProgram();
        return;
    }
    
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter price: $";
    cin >> price;
    
    cout << "Enter stock quantity: ";
    cin >> stock;
    
    // Add to inventory
    if(itemCount < MAX_ITEMS) {
        inventory[itemCount].code = code;
        inventory[itemCount].name = name;
        inventory[itemCount].category = category;
        inventory[itemCount].price = price;
        inventory[itemCount].stock = stock;
        itemCount++;
        cout << "\nItem added successfully!\n";
    } else {
        cout << "\nInventory full! Cannot add more items.\n";
    }
    pauseProgram();
}

void viewAllItemsMenu() {
    displayHeader("ALL ITEMS");
    
    if(itemCount == 0) {
        cout << "No items in inventory.\n";
        pauseProgram();
        return;
    }
    
    cout << left << setw(10) << "Code" 
         << setw(20) << "Name" 
         << setw(15) << "Category" 
         << setw(10) << "Price" 
         << setw(10) << "Stock" << endl;
    cout << string(65, '-') << endl;
    
    for(int i = 0; i < itemCount; i++) {
        cout << left << setw(10) << inventory[i].code
             << setw(20) << inventory[i].name
             << setw(15) << inventory[i].category
             << "$" << setw(9) << fixed << setprecision(2) << inventory[i].price
             << setw(10) << inventory[i].stock << endl;
    }
    pauseProgram();
}

void searchItemMenu() {
    displayHeader("SEARCH ITEM");
    cout << "1. SEARCH BY NAME\n";
    cout << "2. SEARCH BY CODE\n";
    displayHeader("SELECT OPTION");
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        string searchName;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, searchName);
        
        bool found = false;
        for(int i = 0; i < itemCount; i++) {
            if(inventory[i].name.find(searchName) != string::npos) {
                displayItem(inventory[i]);
                found = true;
            }
        }
        if(!found) {
            cout << "Item not found.\n";
        }
    } 
    else if(choice == 2) {
        int searchCode;
        cout << "Enter item code: ";
        cin >> searchCode;
        
        bool found = false;
        for(int i = 0; i < itemCount; i++) {
            if(inventory[i].code == searchCode) {
                displayItem(inventory[i]);
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Item not found.\n";
        }
    } 
    else {
        cout << "Invalid choice!\n";
    }
    pauseProgram();
}

void updateItemMenu() {
    displayHeader("UPDATE ITEM");
    int code;
    cout << "Enter item code to update: ";
    cin >> code;
    
    // Find item
    int foundIndex = -1;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            foundIndex = i;
            break;
        }
    }
    
    if(foundIndex == -1) {
        cout << "Item not found.\n";
        pauseProgram();
        return;
    }
    
    cout << "\nCurrent Details:\n";
    displayItem(inventory[foundIndex]);
    
    cout << "\nEnter new price: $";
    cin >> inventory[foundIndex].price;
    
    cout << "Enter new stock: ";
    cin >> inventory[foundIndex].stock;
    
    cout << "\nItem updated successfully!\n";
    pauseProgram();
}

void deleteItemMenu() {
    displayHeader("DELETE ITEM");
    int code;
    cout << "Enter item code to delete: ";
    cin >> code;
    
    // Find item
    int foundIndex = -1;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            foundIndex = i;
            break;
        }
    }
    
    if(foundIndex == -1) {
        cout << "Item not found.\n";
        pauseProgram();
        return;
    }
    
    // Shift all items after foundIndex
    for(int i = foundIndex; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    
    cout << "Item deleted successfully!\n";
    pauseProgram();
}

void viewStockMenu() {
    displayHeader("VIEW STOCK");
    cout << "1. DRINKS STOCK\n";
    cout << "2. SNACKS STOCK\n";
    cout << "3. CHOCOLATES STOCK\n";
    cout << "4. BISCUITS STOCK\n";
    displayHeader("SELECT OPTION");
    
    int choice;
    cin >> choice;
    
    string category;
    switch(choice) {
        case 1: category = "Drinks"; break;
        case 2: category = "Snacks"; break;
        case 3: category = "Chocolates"; break;
        case 4: category = "Biscuits"; break;
        default: 
            cout << "Invalid choice!\n";
            pauseProgram();
            return;
    }
    
    cout << "\n" << category << " STOCK:\n";
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].category == category) {
            cout << "- " << inventory[i].name << ": " << inventory[i].stock << endl;
            found = true;
        }
    }
    if(!found) {
        cout << "No items in this category.\n";
    }
    pauseProgram();
}

void restockItemMenu() {
    displayHeader("RESTOCK ITEM");
    int code, quantity;
    cout << "Enter item code: ";
    cin >> code;
    
    // Find item
    int foundIndex = -1;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            foundIndex = i;
            break;
        }
    }
    
    if(foundIndex == -1) {
        cout << "Item not found.\n";
        pauseProgram();
        return;
    }
    
    cout << "Current stock: " << inventory[foundIndex].stock << endl;
    cout << "Enter quantity to add: ";
    cin >> quantity;
    
    inventory[foundIndex].stock += quantity;
    cout << "New stock: " << inventory[foundIndex].stock << endl;
    cout << "Restocked successfully!\n";
    pauseProgram();
}

void setPricesMenu() {
    displayHeader("SET PRICES");
    int code;
    double newPrice;
    cout << "Enter item code: ";
    cin >> code;
    
    // Find item
    int foundIndex = -1;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            foundIndex = i;
            break;
        }
    }
    
    if(foundIndex == -1) {
        cout << "Item not found.\n";
        pauseProgram();
        return;
    }
    
    cout << "Current price: $" << inventory[foundIndex].price << endl;
    cout << "Enter new price: $";
    cin >> newPrice;
    
    inventory[foundIndex].price = newPrice;
    cout << "Price updated successfully!\n";
    pauseProgram();
}

// ========================
// CUSTOMER FUNCTION IMPLEMENTATIONS
// ========================
void viewItemsCustomerMenu() {
    displayHeader("AVAILABLE ITEMS");
    
    if(itemCount == 0) {
        cout << "No items available.\n";
        pauseProgram();
        return;
    }
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].stock > 0) {
            displayItem(inventory[i]);
        }
    }
    pauseProgram();
}

void searchItemCustomerMenu() {
    displayHeader("SEARCH ITEM");
    string searchName;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, searchName);
    
    bool found = false;
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].name.find(searchName) != string::npos && inventory[i].stock > 0) {
            displayItem(inventory[i]);
            found = true;
        }
    }
    if(!found) {
        cout << "Item not found or out of stock.\n";
    }
    pauseProgram();
}

void purchaseItemMenu() {
    displayHeader("PURCHASE ITEM");
    
    if(itemCount == 0) {
        cout << "No items available.\n";
        pauseProgram();
        return;
    }
    
    // Display available items
    cout << "Available Items:\n";
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].stock > 0) {
            cout << i+1 << ". " << inventory[i].name << " - $" << inventory[i].price << endl;
        }
    }
    
    int choice, quantity;
    cout << "\nEnter item number: ";
    cin >> choice;
    
    if(choice < 1 || choice > itemCount) {
        cout << "Invalid choice!\n";
        pauseProgram();
        return;
    }
    
    int itemIndex = choice - 1;
    
    if(inventory[itemIndex].stock == 0) {
        cout << "Item out of stock!\n";
        pauseProgram();
        return;
    }
    
    cout << "Enter quantity (1-" << inventory[itemIndex].stock << "): ";
    cin >> quantity;
    
    if(quantity < 1 || quantity > inventory[itemIndex].stock) {
        cout << "Invalid quantity!\n";
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
    displayHeader("SHOPPING CART");
    
    if(cartCount == 0) {
        cout << "Cart is empty.\n";
        pauseProgram();
        return;
    }
    
    double total = 0;
    for(int i = 0; i < cartCount; i++) {
        cout << i+1 << ". " << cart[i].name 
             << " x" << cart[i].quantity 
             << " @ $" << cart[i].price 
             << " = $" << cart[i].total << endl;
        total += cart[i].total;
    }
    
    cout << "\nTotal: $" << total << endl;
    pauseProgram();
}

void checkoutMenu() {
    displayHeader("CHECKOUT");
    
    if(cartCount == 0) {
        cout << "Cart is empty!\n";
        pauseProgram();
        return;
    }
    
    // Calculate total
    double total = 0;
    for(int i = 0; i < cartCount; i++) {
        total += cart[i].total;
    }
    
    cout << "Total amount: $" << total << endl;
    cout << "Your balance: $" << customerBalance << endl;
    
    if(customerBalance >= total) {
        // Process purchase
        customerBalance -= total;
        totalSales += total;
        totalTransactions++;
        
        // Update stock
        for(int i = 0; i < cartCount; i++) {
            for(int j = 0; j < itemCount; j++) {
                if(inventory[j].code == cart[i].code) {
                    inventory[j].stock -= cart[i].quantity;
                    break;
                }
            }
        }
        
        cout << "\n=== RECEIPT ===\n";
        for(int i = 0; i < cartCount; i++) {
            cout << "- " << cart[i].name << " x" << cart[i].quantity 
                 << " = $" << cart[i].total << endl;
        }
        cout << "Total: $" << total << endl;
        cout << "Remaining balance: $" << customerBalance << endl;
        cout << "Thank you for your purchase!\n";
        
        // Clear cart
        cartCount = 0;
    } else {
        cout << "Insufficient balance! Need $" << (total - customerBalance) << " more.\n";
    }
    pauseProgram();
}

void viewPricesMenu() {
    displayHeader("ITEM PRICES");
    
    if(itemCount == 0) {
        cout << "No items available.\n";
        pauseProgram();
        return;
    }
    
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].stock > 0) {
            cout << inventory[i].name << ": $" << inventory[i].price << endl;
        }
    }
    pauseProgram();
}

void addMoneyMenu() {
    displayHeader("ADD MONEY");
    double amount;
    cout << "Enter amount to add: $";
    cin >> amount;
    
    if(amount > 0) {
        customerBalance += amount;
        cout << "Added $" << amount << ". New balance: $" << customerBalance << endl;
    } else {
        cout << "Invalid amount!\n";
    }
    pauseProgram();
}

void viewBalanceMenu() {
    displayHeader("BALANCE");
    cout << "Current balance: $" << customerBalance << endl;
    pauseProgram();
}

// ========================
// UTILITY FUNCTIONS
// ========================
void addSampleData() {
    // Add sample items
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

bool itemCodeExists(int code) {
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].code == code) {
            return true;  // Item found
        }
    }
    return false;  // Item not found
}

bool itemNameExists(string name) {
    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].name == name) {
            return true;  // Item found
        }
    }
    return false;  // Item not found
}

void clearScreen() {
    // Simple clear for most systems
    for(int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void pauseProgram() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
