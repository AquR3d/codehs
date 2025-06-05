#include "util.h"
#include <vector>

const int PUZZLE_SIZE = 9;
const vector<char> NUMS {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Start with your code from the previous problem
void printPuzzle(vector<vector<char> > &puzzle){
    // Enter your code here
    
    for (int r = 0; r < PUZZLE_SIZE; r++) {
        if (r % 3 == 0) cout << "|-----|-----|-----|" << endl;
        for (int c = 0; c < PUZZLE_SIZE; c++) {
            if (c % 3 == 0) cout << "|";
            cout << puzzle[r][c];
            if (c % 3 < 2) cout << " ";
        }
        cout << "|\n"; 
    }
    cout << "|-----|-----|-----|" << endl;
}

bool isValid(vector<vector<char > > &puzzle, int row, int col, char num){
    
    // check 3x3 square
    int startR = (row/3)*3, startC = (col/3)*3, endR = startR+3, endC = startC+3;
    for (int r = startR; r < endR; r++)
        for (int c = startC; c < endC; c++)
            if (puzzle[r][c] == num) return false;
            
    // check columns
    for (int r = 0; r < PUZZLE_SIZE; r++)
        if (puzzle[r][col] == num) return false;
        
    // check rows
    for (int c = 0; c < PUZZLE_SIZE; c++)
        if (puzzle[row][c] == num) return false;
        
    return true;
}

bool nextEmpty(vector<vector<char> > &puzzle, int &row, int &col) {
    
    for (int r = 0; r < PUZZLE_SIZE; r++)
        for (int c = 0; c < PUZZLE_SIZE; c++)
            if (puzzle[r][c] == ' ') { row = r; col = c; return true; }
    return false;
}

bool sudokuSolver(vector<vector<char> > &puzzle) {
    
    int r, c;
    if (!nextEmpty(puzzle, r, c)) return true;
    
    for (int num = 1; num <= 9; num++) {
        
        //readLine("[ENTER]");
        //cout << num << ":" << r << c << endl;
        //printPuzzle(puzzle);
        
        if (!isValid(puzzle, r, c, NUMS[num-1])) continue;
        
        puzzle[r][c] = NUMS[num-1];
        
        
        
        if (sudokuSolver(puzzle)) return true;
    }
    //cout << "RF" << endl;
    puzzle[r][c] = ' ';
    return false;
}

int main(){
    /*vector<vector<char> > puzzle = {
            {'3',' ','6',  '5',' ','8',  '4',' ',' '},
            {'5','2',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ','7',  ' ',' ',' ',  ' ','3','1'},

            {' ',' ','3',  ' ','1',' ',  ' ','8',' '},
            {'9',' ',' ',  '8','6','3',  ' ',' ','5'},
            {' ','5',' ',  ' ','9',' ',  '6',' ',' '},

            {'1','3',' ',  ' ',' ',' ',  '2','5',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ','7','4'},
            {' ',' ','5',  '2',' ','6',  '3',' ',' '},
            };*/
            
    /*vector<vector<char> > puzzle = {
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},

            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},

            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            };*/
            
    vector<vector<char> > puzzle = {
            {' ','6',' ',  ' ','5',' ',  ' ',' ','4'},
            {' ',' ',' ',  ' ',' ',' ',  ' ','6','7'},
            {'4',' ',' ',  ' ','1',' ',  '3',' ',' '},

            {' ',' ',' ',  ' ',' ',' ',  ' ',' ',' '},
            {'3',' ',' ',  ' ','9',' ',  '8',' ',' '},
            {' ',' ','2',  '5',' ',' ',  '4',' ',' '},

            {'6',' ',' ',  '7',' ',' ',  ' ',' ',' '},
            {' ','3',' ',  '2',' ',' ',  '7','8',' '},
            {'9',' ',' ',  '8',' ',' ',  '5',' ',' '},
            };
            
    if (sudokuSolver(puzzle))
        printPuzzle(puzzle);
    else
        cout << "No Solution Possible!" << endl;
    
    return 0;
}