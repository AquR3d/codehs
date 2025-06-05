#include "util.h"
#include <fstream>
#include <vector>
#include <set>

set<string> words;

vector<vector<char> > letters {
    {},{}, {'A','B','C'}, {'D','E','F'},
    {'G','H','I'},{'J','K','L'},{'M','N','O'},
    {'P','Q','R','S'},{'T','U','V'},{'W','X','Y','Z'}};

void loadDict(){
    ifstream in;
    in.open("words.txt");
    string word;
    while (true){
        getline(in, word);
        if (in.fail()) break;
        words.insert(word);
    }
}

// Write your recursive function here
void phoneWordRec(int phoneNumber, string soFar)
{
    if (phoneNumber == 0) {
        // check for dictionary
        if (soFar.length() != 7) return;
        
        for (string word : words) {
            if (soFar == word) {
                cout << soFar << endl;
                return;
            }
        }
        
        return;
    }
    
    int currentNum = phoneNumber % 10;
    
    for (char letter : letters[currentNum])
        phoneWordRec(phoneNumber / 10, letter + soFar);
}

void phoneWord(int phoneNumber)
{
    phoneWordRec(phoneNumber, "");
    cout << "End of List" << endl;
}

int main()
{
    loadDict();
    
    int number = readInt("Please enter a phone number: ");

    // Call your recursive method
    phoneWord(number);

    return 0;
}