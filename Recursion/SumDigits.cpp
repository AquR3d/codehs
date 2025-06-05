#include "util.h"

// Write your recursive function here
int sumOfDigits(int num)
{
    // if we've arrived at the firsts place
    if (num == 0) return 0;
    // return sumOfDigits of digits place before singles, + first place
    return sumOfDigits(num / 10) + (num % 10);
}

int main()
{
    // Enter your code here
    int num = readInt("Please enter an integer: ");
    cout << "Sum of Digits: " << sumOfDigits(num) << endl;
    
    return 0;
}