#include "util.h"
#include <vector>
#include <set>

int CARD_SIZE = 5;
int COLUMN_RANGE = 6; // must be at least CARD_SIZE amount

struct player
{
    string name;
    vector<set<pair<int, bool> > > card; // each set is a column
    // int represents the number, bool represents if marked or not...
};

/* This function will clear any current numbers
 * for a player and create a new player card.
 * Each card should have 5 columns with
 * unique randomly generated numbers accoring
 * to the following:
 * Col 1: 1 - 15
 * Col 2: 16 - 30
 * Col 3: 31 - 45
 * Col 4: 46 - 60
 * Col 5: 61 - 75
 */
void generateCard(player &p){
    
    for (int i = 0; i < CARD_SIZE; i++)
    {
        set<pair<int, bool> > column;
        
        // while 5 numbers haven't been added yet...
        while (column.size() != CARD_SIZE)
        {
            // add a random number based on the current iteration...
            int randNum = randInt(i * COLUMN_RANGE + 1, (i + 1) * COLUMN_RANGE);
            pair<int, bool> bingoNumber {randNum, false};
            column.insert(bingoNumber);
        }
        
        p.card.push_back(column); // add column to player card...
    }
}

/* This function should take a player
 * and print their Bingo Card, tab
 * seperated. Example:
    2	17	34	46	62	
    7	24	35	49	63	
    8	27	37	55	67	
    12	29	41	56	69	
    15	30	43	60	73
  */
void printBlankCard(player &p){
    
    // for CARD_SIZE times...
    for (int i = 0; i < CARD_SIZE; i++)
    {
        // for all sets/columns in the player card...
        for (set<pair<int, bool> > column : p.card)
        {
            // get iterator of current column
            set<pair<int, bool> >::iterator it = column.begin();
            
            // increments iterator i times...
            for (int j = 0; j < i; j++)
            {
                it++;    // this is the only increment operator that worked
                         // i wanted to use it+=i but it just doesnt work ig
                         
                // if iterator is past the end of set or is at the end...
                if (it == column.end()) break; // error handle just in case
            }
            // iterator successfully modified to an ith element...
            
            // prints the ith element of the current column...
            cout << (*it).first << "\t";
        }
        // next row...
        cout << endl;
    }
}

/* The main function should run the menu option
 * and call the sub functions. In this exercise
 * you should complete the menu, but only need
 * to complete options for adding a player,
 * printing the cards, reseting, and exit.
 */
int main(){
    
    vector<player> players;

    while(true)
    {
        // menu prompt
        cout << "Would you like to:" << endl;
        cout << "1) Play one turn" << endl;
        cout << "2) Print player cards" << endl;
        cout << "3) Add a player" << endl;
        cout << "4) Auto play to win" << endl;
        cout << "5) Reset with same players" << endl;
        cout << "6) exit" << endl;
        
        int option = readInt("> ", "Not an option. > "); // user input option prompt
        
        if (option == 6) // exit option
        {
            cout << "Thanks for playing!";
            break;
        }
        
        if (option == 3) // add player option
        {
            string name = readLine("Please enter the player's name: ");
            
            player p;
            p.name = name;
            generateCard(p);
            
            players.push_back(p);
        }
        
        if (option == 2) // print player cards option
        {
            for (player p : players)
            {
                cout << "*******\t" << p.name << "'s Card\t*******" << endl;
                
                printBlankCard(p);
                
                cout << endl;
            }
        }
    }
    
    return 0;
}