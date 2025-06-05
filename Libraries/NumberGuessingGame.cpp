#include "util.h"

int main()
{
    // Enter your code here
    int randNum = randInt(1, 100);
    
    int userNum;
    int count = 0;
    
    do {
        userNum = readInt(1, 100, "Guess a number among 1 and 100: ", "That is not among 1 and 100! Guess again: ");
        count++;
        
        if (userNum < randNum) cout << "Higher!" << endl;
        
        if (userNum > randNum) cout << "Lower!" << endl;
        
    } while (userNum != randNum);
    
    cout << "Congratulations! You guessed the number in " << count << " attempt(s)!";
    
    return 0;
}