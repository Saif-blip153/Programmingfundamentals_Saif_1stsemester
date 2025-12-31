#include <iostream>
#include <string>
#include<cctype>
using namespace std;

int main() {
    char first[30] = "Muhammad ";
    char last[] = "Saif";
    strcat (first, last);
    cout << first;
    return 0;
}

