#include "util.h"
#include <vector>
#include <queue>

// ace, king, queen, jack, numbers...
vector<string> values = {"A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
vector<string> symbols = {"\u2666", "\u2663", "\u2665", "\u2660"}; // diamonds, clubs, hearts, spades
int DECK_SIZE = values.size() * symbols.size();

// Create a makeDeck function that takes
// no input and returns a vector of a
// string/char pairs.
vector<pair<string, string> > makeDeck()
{
    vector<pair<string, string> > newDeck;
    
    // for each suit type of card...
    for (string symbol : symbols)
    {
        // for each value type of card...
        for (string value : values)
        {
            pair<string, string> card; // make an empty card
            card.first = value; // add this iteration's value to card...
            card.second = symbol; // add this iteration's symbol to card...
            
            newDeck.push_back(card); // add card to deck...
        }
    }
    // done
    
    return newDeck;
}

// Create a shuffle function that takes
// a vector of string/char pairs and returns
// a queue of string/char pairs
queue<pair<string, string> > shuffle(vector<pair<string, string> > deck)
{
    queue<pair<string, string> > newDeck;
    
    for (int i = 0; i < DECK_SIZE; i++) // do this for deck times...
    {
        // DECK_SIZE - 1 makes a total of DECK_SIZE indexes when starting w/ 0...
        int randIdx = randInt(0, DECK_SIZE - (1 + i)); 
        
        newDeck.push(deck[randIdx]); // add random card to new deck...
        vector<pair<string, string> >::iterator itr = deck.begin(); // make iterator for old deck...
        deck.erase(itr + randIdx); // remove the random card from old deck to prevent duplicates...
    }
    
    return newDeck;
}


int main()
{
    // Create the deck
    vector<pair<string, string> > deck = makeDeck();
    
    // Shuffle the deck
    queue<pair<string, string> > cardQueue = shuffle(deck);

    // Deal the first 10 cards
    for (int i = 0; i < 10; i++)
    {
        cout << cardQueue.front().first << " - " << cardQueue.front().second << endl;
        cardQueue.pop();
    }

    return 0;
}