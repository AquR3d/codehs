#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    
    cout << "Please enter cents less than 1000: ";
    int cents;
    cin >> cents;
    
    cout << "Quarters: " << cents / 25 << endl;
    cout << "Dimes: " << cents % 25 / 10 << endl;
    cout << "Nickels: " << cents % 25 % 10 / 5 << endl;
    cout << "Pennies: " << cents % 25 % 10 % 5 << endl;
    
    return 0;
}