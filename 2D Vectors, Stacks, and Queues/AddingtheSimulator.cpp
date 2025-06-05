#include "util.h"
#include <vector>

int BOARD_SIZE = 15;
int BOARD_SIZE_SQRD = BOARD_SIZE * BOARD_SIZE;
char deadCell = 'O';
char activeCell = 'X';

void printBoard(vector<vector<char> > &board)
{   
    for (vector<char> row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int getOutCellsAlive(vector<char> &surroundingCells, char alive = activeCell)
{
    int count = 0;
    for (char cell : surroundingCells)
    {
        if (cell == alive) count++;    
    }
    return count;
}

void simulateRound(vector<vector<char> > &cellsNow)
{   
    vector<vector<char> > cellsOg = cellsNow;
    
    for (int row = 0; row < cellsOg.size(); row++)
    {
        for (int col = 0; col < cellsOg[row].size(); col++)
        {
            // make vector for surrounding cells of current cell
            vector<char> outCells;
            
            if (row != 0) outCells.push_back(cellsOg[row - 1][col]); // add cell top
            if (row != cellsOg.size() - 1) outCells.push_back(cellsOg[row + 1][col]); // add cell bottom
            if (col != 0)
            {
                outCells.push_back(cellsOg[row][col - 1]); // add cell left
                if (row != 0) outCells.push_back(cellsOg[row - 1][col - 1]); // add cell top left
                if (row != cellsOg.size() - 1) outCells.push_back(cellsOg[row + 1][col - 1]); // add cell bottom left
            }
            if (col != cellsOg[row].size() - 1)
            {
                outCells.push_back(cellsOg[row][col + 1]); // add cell right
                if (row != 0) outCells.push_back(cellsOg[row - 1][col + 1]); // add cell top right
                if (row != cellsOg.size() - 1) outCells.push_back(cellsOg[row + 1][col + 1]); // add cell bottom right
            }
            // end of making outCells vector
            
            if (cellsOg[row][col] == activeCell) // if current cell is active/'X'
            {
                int count = getOutCellsAlive(outCells);
                if (count != 2 && count != 3) cellsNow[row][col] = deadCell;
            }
            else if (cellsOg[row][col] == deadCell) // if current cell is dead/'O'
            {
                if (getOutCellsAlive(outCells) == 3) cellsNow[row][col] = activeCell;
            }
        }
    }
    return;
}

int main()
{
    // Enter your code here
    // x = alive
    // o = dead
    
    int aCells = readInt(1, BOARD_SIZE_SQRD, "Enter # of active cells 1-225: ", "Not a valid amount. Must be 1-225: ");
    char defaultCell = deadCell;
    char replaceCell = activeCell;
    
    // if user wants to make more active cells than dead cells...
    if (aCells > BOARD_SIZE_SQRD / 2)
    {
        defaultCell = activeCell; // change default cell to generate the active cell...
        replaceCell = deadCell; // and the replace cell the dead cell...
        aCells = BOARD_SIZE_SQRD - aCells;
        // and change cells to change by (max - current cells to change)
        // bc we swapped what cells to change to based on minority
    }
    
    // generate board w/ default cells
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
    for (int i = 0; i < BOARD_SIZE_SQRD; i++)
    {
        cells.push_back(i);
    }
    
    // shuffle indexes
    vector<int>::iterator itr = cells.begin();
    
    for (int i = 0; i < aCells; i++)
    {
        // make a random idx for an unswapped cell
        int randIdx = randInt(i, BOARD_SIZE_SQRD - 1);
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
    
    string input;
    
    do {
        
        printBoard(board);
        
        simulateRound(board);
        
        input = readLine("[Enter] to continue ('exit' to quit) ");
        
    } while (input != "exit");
    
    return 0;
}