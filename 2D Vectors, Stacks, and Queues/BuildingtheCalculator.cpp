#include "util.h"
#include <vector>
#include <stack>

int main()
{
    // Enter your code here
    stack<double> num;
    
    string command = "";
    bool calculate = false;
    
    while (true)
    {
        // prompt
        cout << "> ";
        cin >> command;
        cin.ignore();
        
        // if exit is typed... exit
        if (command == "exit") break;
        
        // classify what was typed in...
        try
        {
            num.push(stod(command)); // works if a number is put in...
            calculate = false; // set to false bc we don't have an operator...
        }
        catch(invalid_argument) // not a number so goes here...
        {
            if (command.length() > 1) continue; // if it's just a rando word...
            switch (command[0]) // command[0] just to get first letter aka char
            {
                // if it's an operator... then change calculate to true for next section...
                case '*': case '/': case '-': case '+': calculate = true; break;
                default: continue; // if it's just a rando single character...
            }
        }
        
        // NOW IT'S CALCULATING TIME
        if (calculate) // if what was put in was an operator...
        {
            if (num.size() < 2) // if not enough numbers to calculate with...
            {
                cout << "Error - Not enough numbers in stack" << endl;
                continue; // restart loop
            }
            
            double result = num.top(); // save top num in stack
            num.pop(); // get rid of it now
            switch(command[0]) // now we test what operator we have
            {
                case '+': result += num.top(); break; // do the operation
                case '-': result = num.top() - result; break;
                case '*': result *= num.top(); break;
                case '/': result = num.top() / result; break;
            }
            num.pop(); // get rid of the second term used of already done calculation
            num.push(result); // add result to stack as another term
            
            cout << num.top() << endl; // print the result
        }
    }
    
    return 0;
}