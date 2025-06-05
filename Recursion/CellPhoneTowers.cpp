#include "util.h"
#include <vector>
#include <map>
#include <cmath> // used for the sqrt function

// Cell tower struct
struct cellTower {
    int x, y;
};

const int GRID_SIZE = 10;
const double FREQ_DISTANCE = 5.6;
const double TOWER_DISTANCE = 2.1;
//  The FREQ vector  may have more frequencies than needed
const vector<char> FREQ {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// Helper function to print grid
void printGrid(vector<vector<char> > grid) {
    for (int row = 0; row < GRID_SIZE; row ++) {
        for (int col = 0; col < GRID_SIZE; col ++) {
            cout << grid[row][col] << ' ';
        }
        cout << endl;
    }
}

// Helper function to determine the distance between points.
// x and y should represent the grid coordinates.
double distance(int x1, int y1, int x2, int y2) {
    int a = x2 - x1;
    int b = y2 - y1;
    return sqrt(a * a + b * b);
}
// Helper function to determine if a tower is needed
// Returns true if distance of point is less than TOWER_DISTANCE
bool towerNeeded(vector<vector<char> >& grid, int testRow, int testCol) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] != '.') {
                if (distance(row, col, testRow, testCol) < TOWER_DISTANCE) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Helper function to find the next valid frequency
// Returns the next frequency to use
char validFreq(vector<vector<char> >& grid, int testRow, int testCol, int numFreq) {
    for (char freq : FREQ) {
        bool valid = true;
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                if (grid[row][col] != '.') {
                    if (distance(row, col, testRow, testCol) < FREQ_DISTANCE && grid[row][col] == freq) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }
        if (valid) return freq;
    }
    return '.';  // If no valid frequency found
}

// Solver recursive function.
bool cellSolver(vector<vector<char> >& grid, int row, int col, int numFreq) {
    if (numFreq == 0) return true;  // Base case: all frequencies placed
    
    for (char freq : FREQ) {
        if (validFreq(grid, row, col, numFreq) == freq) {
            if (!towerNeeded(grid, row, col)) {
                grid[row][col] = freq;
                
                // Recursively try placing next tower
                if (col + 1 < GRID_SIZE) {
                    if (cellSolver(grid, row, col + 1, numFreq - 1)) return true;
                } else if (row + 1 < GRID_SIZE) {
                    if (cellSolver(grid, row + 1, 0, numFreq - 1)) return true;
                } else {
                    return true;  // Grid is filled
                }
                
                // Backtrack
                grid[row][col] = '.';
            }
        }
    }
    return false;
}

// Helper function to kick off problem 
bool cellProblem(vector<vector<char> > &grid, int numFreq) {
    // Enter your code here
    return cellSolver(grid, 0, 0, numFreq);
}

int main() {
    // Create the empty grid of size GRID_SIZE. 
    // Place a '.' in each square
    vector<vector<char> > grid {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
   
    // Prompt the user for the number of frequecies
    int numFreq = readInt(1, 10, "Please select the number of frequencies to test (1 - 10): ");
    
    if (!cellProblem(grid, numFreq)) {
        cout << "No Solution possible." << endl;
    } else {
        cout << "Solved!" << endl;
        printGrid(grid);
    }
    
    return 0;
}