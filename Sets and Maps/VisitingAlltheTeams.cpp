#include "util.h"
#include <set>

int main(){

    // Enter your code here
    set<int> teams;
    
    while (true)
    {
        // prompt
        cout << "Please select an option:" << endl;
        cout << "1. Add a team" << endl;
        cout << "2. List all teams" << endl;
        cout << "3. Exit" << endl;
        int option = readInt(">> ");
        // prompting done
        
        // selection types
        if (option == 3) break; // exit program
        
        if (option == 1) // add team
        {
            pair<set<int>::iterator, bool> rtrn = teams.insert(readInt("Enter a team number: "));
            
            if (!rtrn.second) // if team was already added...
            {
                cout << "You already visited team " << *rtrn.first << endl;
            }
            else // if team was added now...
            {
                cout << "Added team " << *rtrn.first << endl;
            }
        }
        
        if (option == 2) // list visited teams
        {
            cout << "Teams visited:" << endl;
            
            for (set<int>::iterator itr = teams.begin(); itr != teams.end(); itr++)
            {
                cout << *itr << endl;
            }
        }
    }

    return 0;
}