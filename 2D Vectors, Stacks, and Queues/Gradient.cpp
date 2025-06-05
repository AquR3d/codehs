#include "util.h"

// Enter your code here

int main()
{
    int w = readInt(1, 100, "Enter grid width: ", "Not a valid width. Try again: ");
    
    int h = readInt(1, 100, "Enter grid height: ", "Not a valid height. Try again: ");
    
    int seed = readInt("Enter seed value: ");
    
    int step = readInt("Enter step value: ");
    
    vector<vector<int> > nums;
    
    // create grid
    for (int row = 0; row < h; row++)
    {
        vector<int> num;
        for (int col = 0; col < w; col++)
        {
            // col * step = add step col amount of times
            num.push_back(seed + (col * step));  
        }
        seed += step;
        nums.push_back(num);
    }
    
    // print grid
    for (vector<int> row : nums)
    {
        for (int num : row)
        {
            cout << num << "\t";    
        }
        cout << endl;
    }
    
    return 0;
}