#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    // 1. substr() - Get part of "Saif"
    string name = "Saif Ali Khan";
    string part = name.substr(0, 4);
    cout << "1. substr(0, 4): " << part << endl;
    // 2. strcat() - Join "Saif" with another string
    char first[20] = "My name: ";
    char last[] = "Saif";
    strcat(first, last);
    cout << "2. strcat: " << first << endl;
    // 3. strcmp() - Compare with "Saif"
    char name1[] = "Saif";
    char name2[] = "Saif";
    if(strcmp(name1, name2) == 0)
        cout << "3. strcmp: Both are Saif" << endl;
    else
        cout << "3. strcmp: Names are different" << endl;
    // 4. strcpy() - Copy "Saif" to another variable
    char original[] = "Saif";
    char copy[10];
    strcpy(copy, original);
    cout << "4. strcpy: " << copy << endl;
    // 5. strlen() - Get length of "Saif"
    char text[] = "Saif";
    int length = strlen(text);
    cout << "5. strlen: Saif has " << length << " letters" << endl;    
    // 6. strncat() - Join with limit using "Saif"
    char greeting[20] = "Hello ";
    char friendName[] = "Saif Ali";
    strncat(greeting, friendName, 4);
    cout << "6. strncat: " << greeting << endl; 
    return 0;
}
