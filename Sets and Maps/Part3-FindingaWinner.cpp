#include "util.h"
#include <vector>
#include <set>

int CARD_SIZE = 5; // bingo card length/width
int COLUMN_RANGE = 15; // must be at least CARD_SIZE amount... !!!!IMPORTANT!!!!
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

bool numberInSet(set<int> &numbers, int num)
{
    for (int number : numbers)
    {
        if (num == number) { return true; }    
    }
    return false;
}

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

void printBlankCard(player &p){
    
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
                // if the number is in the set...
                if (marked = numberInSet(numbers, *it)) cout << "X\t"; // print X
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
        
        cout << endl;
    }
}

/* This function will take the set of
 * numbers and a player's card and
 * return true if their card has bingo. Otherwise
 * return false.
 * A card has bingo if all the numbers in a row,
 * column, or one of the diagonals have been
 * called.
 */
bool checkWinner(set<int> &numbers, player &p){
    
    if (numbers.empty()) return false; // if no numbers to check from...
    
    bool winnerAtm = false;
    set<int>::iterator columnItr;
    
    ////////////
    // check DIAGONALS for match...
    
    // negative diagonal (top left-btm right)
    int colIdx = 0; // column index aka which column
    while (columnItr != p.card[colIdx].end() && colIdx < CARD_SIZE)
    {
        columnItr = p.card[colIdx].begin();
        for (int i = 0; i < colIdx; i++) columnItr++;
        
        winnerAtm = numberInSet(numbers, *columnItr);
        if (!winnerAtm) break;

        colIdx++;
    }
    // if winnerAtm maintained its true state bc/ it was not proven otherwise... return true
    if (winnerAtm) return true;
    
    // else...
    
    // positive diagonal
    winnerAtm = true; // assume this positive diagonal could be a winner
    colIdx = CARD_SIZE - 1; // column index set to the rightest column aka last column
    while (columnItr != p.card[colIdx].end() && colIdx >= 0) // while current element is not the last one
    {
        columnItr = p.card[colIdx].begin(); // element is the start of current column...
        for (int i = CARD_SIZE - 1; i > colIdx; i--) columnItr++; // set element down by CARD_SIZE-1 - colIDX amt...
        
        winnerAtm = numberInSet(numbers, *columnItr); // stores if current element is in the bingo set...
        if (!winnerAtm) break; // if it doesn't then stop checking this diagonal...
        // else... move onto the next column, which is the left column
        colIdx--;
    }
    // if winnerAtm maintained its true state bc/ it was not proven otherwise... return true
    if (winnerAtm) return true;
    
    // else... aka if it was proven otherwise that the diagonals were not bingos.... (bingoes?)
    
    ////////////
    // check COLUMNS for match...
    colIdx = 0; // start at the first column...
    while (colIdx < CARD_SIZE && !winnerAtm) // for each column & that prev col was not a bingo...
    {
        columnItr = p.card[colIdx].begin(); // iterator set to start of column...
        winnerAtm = true; // assume this column may be a winner until proven otherwise...
        while (columnItr != p.card[colIdx].end()) // while itr has not reached end of col...
        {
            // if the current number at the iterator is not in the bingo set...
            winnerAtm = numberInSet(numbers, *columnItr);
            if (!winnerAtm) break; // move onto next column...
            columnItr++; // move onto next element in column...
        }
        colIdx++; // move onto next column...
    }
    // if winnerAtm maintained its true state bc/ it was not proven otherwise... return true
    if (winnerAtm) return true;
    
    // else....
    
    ////////////
    // check ROWS for match...
    colIdx = 0; // column index aka which column
    columnItr = p.card[colIdx].begin();
    int row = 0; // row index to keep track of what row is being examined...
    while (row < CARD_SIZE && !winnerAtm) // for each row & that previous row wasn't bingo...
    {
        // assume this may be a winner row for now...
        winnerAtm = true;
        colIdx = 0; // start at the beginning of the row...
        while (colIdx < CARD_SIZE) // while this is not the end of this row...
        {
            // calculate iterator to align with row index...
            columnItr = p.card[colIdx].begin();
            for (int i = 0; i < row; i++) columnItr++; // increments itr for row amt...
            
            // if the current number at the iterator is not in the bingo set...
            winnerAtm = numberInSet(numbers, *columnItr); // say this row is not a winner...
            if (!winnerAtm) break; // move on to next row...
            
            colIdx++; // increase idx to be next element in the row...
        }
        row++; // increment to go onto next row...
    }

    return winnerAtm; // returns true if a row maintained its winner state, false if not...
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
            
            generateCard(p); // make card
            printBlankCard(p); // and print their card
            
            players.push_back(p); // add to player list...
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
            
            for (player p : players)
            {
                if (checkWinner(bingoNums, p))
                {
                    cout << p.name << " won!" << endl;
                    break;
                }
            }
        }
        
        if (option == 4)
        {
            bool bingo = false;
            int turn = 0;
            while (!bingo)
            {
                cout << "************************" << endl;
                cout << "*****  Round " << turn << "\t*****" << endl;
                cout << "************************" << endl << endl;
                playTurn(bingoNums, players);
                
                turn++;
                
                // for each player...
                for (player p : players)
                {
                    // check if they have a bingo
                    bingo = checkWinner(bingoNums, p);
                    if (bingo)
                    {
                        cout << "Congrats to " << p.name << "!" << endl << endl;
                        break;
                    }
                }
            }
        }
        
        if (option == 5)
        {
            if (players.empty()) cout << "Please add some players to reset." << endl;
            else bingoNums.clear();    
        }

    }
    
    return 0;
}