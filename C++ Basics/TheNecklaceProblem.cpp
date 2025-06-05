#include <iostream>

using namespace std;

int main()
{
    int orig1, orig2, steps = 0;
    cout << "Please enter two digits seperated by a space: ";
    // Notice how we can read two values in one line
    cin >> orig1 >> orig2;
    
    int digit1 = orig1, digit2 = orig2;
    
    while (true)
    {
        cout << digit1 << " "; 
        int prevDigit2 = digit2;
        digit2 = (digit1 + digit2) % 10;
        digit1 = prevDigit2;
        steps++;
        
        if (digit1 == orig1 && digit2 == orig2)
        {
            cout << digit1 << " " << digit2 << endl;
            break;    
        }
    }
    
    cout << "Total Steps: " << steps;
   
    return 0;
}