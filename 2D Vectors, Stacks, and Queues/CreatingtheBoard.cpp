#include "util.h"
#include <vector>

int BOARD_SIZE = 15;

int main()
{
    // Enter your code here
    // x = alive
    // o = dead
    
    int aCells = readInt(1, BOARD_SIZE * BOARD_SIZE, "Enter # of active cells 1-225: ", "Not a valid amount. Must be 1-225: ");
    char defaultCell = 'O';
    char replaceCell = 'X';
    
    // if user wants to make more active cells than dead cells...
    if (aCells > BOARD_SIZE * BOARD_SIZE / 2)
    {
        defaultCell = 'X'; // change default cell to generate the active cell...
        replaceCell = 'O'; // and the replace cell the dead cell...
        aCells = BOARD_SIZE * BOARD_SIZE - aCells;
        // and change cells to change by (max - current cells to change)
        // bc we swapped what cells to change to based on minority
    }
    
    // generate board w/ dead cells
    vector<vector<char> > board;
    
    for (int i = 1; i <= BOARD_SIZE; i++)
    {
        vector<char> row;
        for (int j = 1; j <= BOARD_SIZE; j++)
        {            
            row.push_back(defaultCell);
        }
        board.push_back(row);
    }
    
    // generate random indexes for alive cells
    vector<int> cells;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        cells.push_back(i);
    }
    
    // shuffle indexes
    vector<int>::iterator itr = cells.begin();
    
    for (int i = 0; i < aCells; i++)
    {
        // make a random idx for an unswapped cell
        int randIdx = randInt(i, BOARD_SIZE * BOARD_SIZE - 1);
        cells.insert(itr, cells[randIdx]); // insert num @ cell @ randIdx to front
        itr = cells.begin(); // update iterator bc vector length changed
        cells.erase(itr + randIdx + 1); // erase cell @ og randIdx (add 1 bc we just
                                        // added one to the vector w/ the insert)
        itr = cells.begin(); // update iterator bc vector length changed
    }
    
    // replace randomized indexed cells with minority cell
    for (int i = 0; i < aCells; i++)
    {
        board[cells[i] / BOARD_SIZE][cells[i] % BOARD_SIZE] = replaceCell;
    }
    // get rid of cells as it is not needed anymore bc randomization is complete
    cells.clear();
    
    // print board
    
    //int count = 0;
    for (vector<char> row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
            //if (cell == 'X') count++;
        }
        cout << endl;
    }
    //cout << count;
    
    return 0;
}