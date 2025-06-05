#include "util.h"

int main()
{
    // Enter your code here
    int playerScore = 0;
    int turnCount = 1;
    
    while (playerScore < 100)
    {
        int roundScore = 0;
        
        cout << "Turn " << turnCount << endl;
        cout << "Your Current Score is : " << playerScore << endl;
        cout << "This round you have: " << roundScore << endl;
        
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
                playerScore += roundScore;
                rolling = false;
            }
            
            if (playerInput == "roll")
            {
                int roll = randInt(1, 6);
                cout << endl << "You rolled a " << roll << "." << endl;
                
                if (roll == 1) 
                {
                    cout << "You rolled a 1! You get a zero for this round!" << endl;
                    roundScore = 0;
                    rolling = false;
                }
                else
                {
                    roundScore += roll;
                    cout << "This round you have: " << roundScore << endl;
                }
            }
    
        } while (rolling);
        
        turnCount++;
        cout << endl;
    }
    
    cout << "Congratulations! You won in " << turnCount << " turns!";
    
    return 0;
}