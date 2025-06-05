#include "util.h"
#include <vector>
#include <set>

int CARD_SIZE = 5; // bingo card length/width
int COLUMN_RANGE = 15; // must be at least CARD_SIZE amount...
/* why? bc/ the bingo card is designed to not have duplicates
 * , and if the column range is less than the card_size, there is 100% chance in
 * creating a duplicate, so my generate card thing loop sforever bc it keeps running
 * until the random number generator doesnt make a duplicate, and if it alwways makes
 * a duplicate then... yeah infinite loop
 */

struct player
{
    string name;
    vector<set<int> > card; // each set is a column
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
        set<int> column;
        
        // while CARD_SIZE numbers haven't been added yet...
        while (column.size() != CARD_SIZE)
        {
            // add a random number based on the current iteration...
            int randNum = randInt(i * COLUMN_RANGE + 1, (i + 1) * COLUMN_RANGE);
            column.insert(randNum);
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
void printBlankCard(player &p, bool marked = false){
    
    // for CARD_SIZE times...
    for (int i = 0; i < CARD_SIZE; i++)
    {
        // for all sets/columns in the player card...
        for (int col = 0; col < p.card.size(); col++)
        {
            // get iterator of current column
            set<int>::iterator it = p.card[col].begin();
            
            // increments iterator i times...
            for (int j = 0; j < i; j++)
            {
                it++;    // this is the only increment operator that worked
                         // i wanted to use it+=i but it just doesnt work ig
                         
                // if iterator is past the end of set or is at the end...
                if (it == p.card[col].end()) break; // error handle just in case
            }
            // iterator successfully modified to an ith element...
            
            cout << *it << "\t";
        }
        // next row...
        cout << endl;
    }
}

/* This function should print the player's cards with 
 * numbers in the numbers vector marked on their card
 */
void printMarkedCard(set<int> &numbers, player &p){
    // Copy your code from the previous exercise
    // for CARD_SIZE times...
    for (int i = 0; i < CARD_SIZE; i++)
    {
        // for all sets/columns in the player card...
        for (int col = 0; col < p.card.size(); col++)
        {
            // get iterator of current column
            set<int>::iterator it = p.card[col].begin();
            
            // increments iterator i times...
            for (int j = 0; j < i; j++)
            {
                it++;    // this is the only increment operator that worked
                         // i wanted to use it+=i but it just doesnt work ig
                         
                // if iterator is past the end of set or is at the end...
                if (it == p.card[col].end()) break; // error handle just in case
            }
            // iterator successfully modified to an ith element...
            
            // check if its a potential bingo number...
            bool marked = false;
            if (!numbers.empty())
            {
                for (int bNum : numbers)
                {
                    if (*it == bNum)
                    {
                        cout << "X\t";
                        marked = true;
                        break;
                    }
                }
            }
            
            // if an "X" wasn't printed out...
            if (!marked)
            {
                // prints the ith element of the current column...
                cout << *it << "\t"; // print the number
            }
        }
        // next row...
        cout << endl;
    }
}

/* This function simulates a bingo pull and prints
 * the player card results from it
 */
void playTurn(set<int> &numbers, vector<player> &players) {
    // Copy your code from the previous exercise
    int bingoNum; // variable for random bingo num, and to keep in scope...
    // make new random num to add to bingo pool...
    do { bingoNum = randInt(1, CARD_SIZE * COLUMN_RANGE); }
    while(!numbers.insert(bingoNum).second); // while there are duplicates...
    // no duplicates at this point...
    
    cout << "You pulled a " << bingoNum << endl;
    
    // scratch number from player cards...
    
    // for each player...
    for (int i = 0; i < players.size(); i++)
    {
        // print their name...
        cout << "*******\t" << players[i].name << "'s Card\t*******" << endl;
        // and card
        printMarkedCard(numbers, players[i]);
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
    set<int> bingoNums;

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
            // for each player card...
            for (player p : players)
            {
                // print their name...
                cout << "*******\t" << p.name << "'s Card\t*******" << endl;
                // and card
                printBlankCard(p);
                cout << endl; // and enter/next line
            }
        }
        
        if (option == 1 && players.empty()) // play a turn failed option...
        {
            cout << "Please add some players to play a turn." << endl;
        }
        
        if (option == 1 && !players.empty()) // play a turn option...
        {
            playTurn(bingoNums, players);
        }
    }
    
    return 0;
}