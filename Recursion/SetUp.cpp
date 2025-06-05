#include "util.h"
#include <vector>

void printPuzzle(vector<vector<char> > &puzzle){
    // Enter your code here
    
    int size = puzzle.size();
    for (int r = 0; r < size; r++) {
        if (r % 3 == 0) cout << "|-----|-----|-----|" << endl;
        for (int c = 0; c < size; c++) {
            if (c % 3 == 0) cout << "|";
            cout << puzzle[r][c];
            if (c % 3 < 2) cout << " ";
        }
        cout << "|\n"; 
    }
    cout << "|-----|-----|-----|" << endl;
}


int main(){
    vector<vector<char> > puzzle = {
            {'3',' ','6',  '5',' ','8',  '4',' ',' '},
            {'5','2',' ',  ' ',' ',' ',  ' ',' ',' '},
            {' ',' ','7',  ' ',' ',' ',  ' ','3','1'},

            {' ',' ','3',  ' ','1',' ',  ' ','8',' '},
            {'9',' ',' ',  '8','6','3',  ' ',' ','5'},
            {' ','5',' ',  ' ','9',' ',  '6',' ',' '},

            {'1','3',' ',  ' ',' ',' ',  '2','5',' '},
            {' ',' ',' ',  ' ',' ',' ',  ' ','7','4'},
            {' ',' ','5',  '2',' ','6',  '3',' ',' '},
            };

    printPuzzle(puzzle);
    return 0;
}