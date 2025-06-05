#include <iostream>

using namespace std;

string encrypt(string phrase, int shift = 26);
string decrypt(string phrase, int shift = 26);
bool isCapital(char letter);
bool isLowerCase(char letter);

int main()
{
    // Enter your code here
    cout << "Enter a phrase: ";
    string text;
    getline(cin, text);
    
    cout << "(E)ncrypt or (D)ecrypt? ";
    char encryptionType;
    cin >> encryptionType;
    
    cout << "Cipher shift amount (1-26): ";
    int changeAmt;
    cin >> changeAmt;
    
    
    string newText;
    if (toupper(encryptionType) == 'E')
        newText = encrypt(text, changeAmt);
    else
        newText = decrypt(text, changeAmt);
        
    cout << newText;
    
    return 0;
}

string encrypt(string phrase, int shift)
{
    int phraseLength = phrase.length(); // phrase.size();
    
    for (int i = 0; i < phraseLength; i++)
    {
        char letter;
        if (isCapital(letter = phrase[i]))
        {
            phrase.replace(i, 1, 1, (letter - 'A' + shift) % 26 + 'A');
        }
        
        if (isLowerCase(letter = phrase[i]))
        {
            phrase.replace(i, 1, 1, (letter - 'a' + shift) % 26 + 'a');
        }
    }
    return phrase;
}

string decrypt(string phrase, int shift)
{
    int phraseLength = phrase.length(); // phrase.size();
    
    for (int i = 0; i < phraseLength; i++)
    {
        char letter;
        if (isCapital(letter = phrase[i]))
        {
            phrase.replace(i, 1, 1, (letter - 'A' + (26 - shift)) % 26 + 'A');
        }
        
        if (isLowerCase(letter = phrase[i]))
        {
            phrase.replace(i, 1, 1, (letter - 'a' + (26 - shift)) % 26 + 'a');
        }
    }
    return phrase;
}

bool isCapital(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return true;
    return false;
}

bool isLowerCase(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return true;
    return false;
}