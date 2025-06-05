#include "util.h"
#include <vector>

/* This function will print your triangle. Call it
 * from your base case. It should not be altered.
 */
 
void printTriangle(vector<vector<int> > &t){
    int size = t.size();
    if (size % 2 == 1) {
        size --;
    }
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < (size - i) / 2; j ++){
            cout << "\t";
        }
        for (int item : t[i]){
            if (i % 2 == 1){
                cout << "   ";
            }
            cout << item << "\t"; 
        }
        cout << endl;
    }
}

/* This will be your recursive function. */
void pascalRec(vector<vector<int> > &t, int remain){

    // Enter your code here.
    
    if (remain == 0)
    {
        printTriangle(t);
        return;    
    }

    vector<int> level {1};
    
    for (int elem = 0; elem < t[t.size()-1].size()-1; elem++)
    {
        int num = t[t.size()-1][elem] + t[t.size()-1][elem+1];
        
        level.push_back(num);
    }
    
    level.push_back(1);
    
    t.push_back(level);
    
    pascalRec(t, remain-1);
    
}

/* This is your helper function. It is set up
 * to create the first row of the Pascal
 * triangle and then call the recursive function.
 * It should not be altered.
 */
void pascal(int levels){
    vector<vector<int> > triangle {{1}};
    pascalRec(triangle, levels - 1);
    //printTriangle(triangle);
}

int main()
{
    int lines = readInt(1,15, "Please enter the number of lines (1 to 15): ");
    pascal(lines);
    
    return 0;
}