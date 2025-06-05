#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    
    string phrase = "Please enter the number of ";
    
    cout << phrase << "Chicken Sandwiches: ";
    int sandwiches;
    cin >> sandwiches;
    
    cout << phrase << "Waffle Fries: ";
    int fries;
    cin >> fries;
    
    cout << phrase << "Sodas: ";
    int sodas;
    cin >> sodas;
    
    cout << "Subtotal: $" << (sandwiches * 3.9) + (fries * 2.2) + (sodas * 1.6) << endl;
    cout << "Tax: $" << ((sandwiches * 3.9) + (fries * 2.2) + (sodas * 1.6)) * 0.1 << endl;
    cout << "Total: $" << ((sandwiches * 3.9) + (fries * 2.2) + (sodas * 1.6)) * 1.1;
    
    return 0;
}