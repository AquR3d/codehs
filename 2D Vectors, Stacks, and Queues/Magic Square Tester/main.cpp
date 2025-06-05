#include "util.h"
#include <fstream>

// Return the sum of the values in the given row
int sumRow(vector<vector<int> > &square, int row) {
    int sum = 0;
    
    for (int num : square[row])
    {
        sum += num;    
    }
    
    return sum;
}

// Return the sum of the values in the given column
int sumCol(vector<vector<int> > &square, int col){
    int sum = 0;
    for (vector<int> row : square)
    {
        sum += row[col];
    }
    return sum;
}

// Return the sum of the values in the main diagonal
int sumMainDiag(vector<vector<int> > &square){
    int sum = 0;
    for (int i = 0; i < square.size(); i++)
    {
        sum += square[i][i];
    }
    return sum;
}

// Return the sum of the values in the other ("reverse") diagonal
int sumOtherDiag(vector<vector<int> > &square){
    int sum = 0;
    for (int i = square.size() - 1; i >= 0; i--)
    {
        sum += square[square.size() - i - 1][i];
    }
    return sum;
}

// Return true if the square is magic (all rows, cols, and diags have
// same sum), false otherwise
bool magic(vector<vector<int> > &square){
    
    int sameValue = sumMainDiag(square);
    if (sumOtherDiag(square) != sameValue) return false;
    
    
    for (int row = 0; row < square.size(); row++)
    {
        if (sumRow(square, row) != sameValue) return false;
        
        for (int col = 0; col < square[row].size(); col++)
        {
            if (sumCol(square, col) != sameValue) return false;
        }
    }
    
    return true;
}

// Print the contents of the square, neatly formatted
void printSquare(vector<vector<int> > &square){
    
    for (vector<int> row : square)
    {
        for (int num : row)
        {
            cout << num << "\t";    
        }
        cout << endl;
    }
}

int main() {
    ifstream in;
    in.open("magic_data.txt");
    if(in.fail())
        Error("File didn't open - check the name");
        
    int count = 1; //count which square we're on     
    
    string line;
    getline(in, line);
    int size = stoi(line); //size of next square

	//Expecting -1 at bottom of input file
	while (size != -1) {
	    //create a new square and read in the data
	    vector<vector<int> > square;
        for (int i = 0; i < size; i++){
            vector<int> row;
            getline(in, line);
            vector<string> input = splitLine(line);
            for(int j = 0; j < input.size(); j++){
                row.push_back(stoi(input[j]));
            }
            square.push_back(row);
        }
        // Print out
		cout << "******** Square " << count << " ********" << endl;
        printSquare(square);
        
        // Display results
        if (magic(square)){
            cout << "The Square is magic! Everything sums to ";
            cout << sumRow(square, 0) << "." << endl; 
        }
        else {
            cout << "The Square is not a magic square." << endl;
        }
        
        getline(in, line);
        size = stoi(line); //size of next square
        count ++;
	}
    return 0;
}