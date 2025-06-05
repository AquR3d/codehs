#include "util.h"
#include <stack>

int main()
{
    // Enter your code here
    stack<string> websites;
    stack<string> history;
    
    // prompting
    while (true)
    {
        cout << "Would you like to: " << endl;
        cout << "1 - Go to a new site" << endl;
        cout << "2 - Go Back" << endl;
        cout << "3 - Go Forward" << endl;
        cout << "4 - Exit" << endl;
        
        string input = readLine(">> ");
        int selection = 0;
        
        try { selection = stoi(input); } catch(invalid_argument) { cout << "Not an option." << endl; }
        
        if (selection == 1) // add to stack
        {
            string newSite = readLine("Enter the new site to browse: ");
            websites.push(newSite);
            cout << "You are currently browsing " << websites.top() << endl;
        }
        
        if (selection == 2) // remove top to access behind
        {
            if (websites.size() < 2) cout << "You do not have any history" << endl;
            else // if we can go back
            {
                history.push(websites.top()); // save website in history
                
                websites.pop(); // remove from current websites
                cout << "You are currently browsing " << websites.top() << endl;
            }
        }
        
        if (selection == 3)
        {
            // if we have no history aka can't go forward...
            if (history.empty()) cout << "You do not have any history" << endl;
            else // if there is forward history
            {
                cout << "You are currently browsing " << history.top() << endl; // print latest forward history
                
                websites.push(history.top()); // add that website back
                history.pop(); // pop it from history bc/ it's what we're currently browsing
            }
        }
        
        if (selection == 4) return 0;
        
        cout << endl;
    }
}