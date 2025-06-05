#include "util.h"

struct player
{
    int score, roundScore;   
};

int main()
{
    // Enter your code here
    player user;
    player computer;
    
    int winningScore = 100;
    int turnCount = 1;
    
    while (user.score < winningScore && computer.score < winningScore)
    {        
        user.roundScore = 0;
        computer.roundScore = 0;
        cout << "Turn " << turnCount << endl;
        cout << "Your Current Score is : " << user.score << endl;
        cout << "Computer Current Score is : " << computer.score << endl;
        cout << "This round you have: " << user.roundScore << endl;
        
        // prompting for loop
        bool rolling = true;
        
        string playerInput;
        do {
            try
            {
                playerInput = readLine("Would you like to roll or bank? ");
                if (playerInput != "roll" && playerInput != "bank") throw logic_error("Not a valid option.");

            }
            catch (logic_error const& x)
            {
                cout << x.what() << endl;
            }
            
            if (playerInput == "bank")
            {
                user.score += user.roundScore;
                rolling = false;
            }
            
            if (playerInput == "roll")
            {
                int roll = randInt(1, 6);
                cout << endl << "You rolled a " << roll << "." << endl;
                
                if (roll == 1) 
                {
                    cout << "You rolled a 1! You get a zero for this round!" << endl;
                    user.roundScore = 0;
                    rolling = false;
                }
                else
                {
                    user.roundScore += roll;
                    cout << "This round you have: " << user.roundScore << endl;
                }
            }
    
        } while (rolling);
        
        rolling = true;
        // computer
        do {
            
            if (computer.roundScore > 15)
            {
                cout << "The computer decided to bank." << endl;
                computer.score += computer.roundScore;
                rolling = false;
            }
            
            if (computer.roundScore <= 15)
            {
                int roll = randInt(1, 6);
                cout << endl << "The computer rolled a " << roll << "." << endl;
                
                if (roll == 1) 
                {
                    cout << "The computer rolled a 1. End of turn." << endl;
                    computer.roundScore = 0;
                    rolling = false;
                }
                else
                {
                    computer.roundScore += roll;
                    cout << "This round the computer has: " << computer.roundScore << endl;
                }
            }
    
        } while (rolling);
        
        turnCount++;
        cout << endl;
    }
    
    if (user.score > computer.score)
        cout << "Congratulations! You won in " << turnCount << " turns!";
        
    if (computer.score > user.score)
        cout << "Good try! The computer won in " << turnCount << "turns.";
    
    return 0;
}