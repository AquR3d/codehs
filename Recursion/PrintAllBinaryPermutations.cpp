#include "util.h"

void printCombos(int numDigits, string soFar) {
    // Base Case
    if (numDigits == 0)
    {
        cout << soFar << endl;
        return;
    }
    // Recursive call
    
    printCombos(numDigits-1, soFar + "0");
    printCombos(numDigits-1, soFar + "1");
}

// Set up function to call the initial recursive function
void printBinary(int numDigits) {
    printCombos(numDigits, "");
}

int main()
{
    int digits = readInt(1, 10, "Select the number of digits (1 to 10): ");

    printBinary(digits);
    
    return 0;
}