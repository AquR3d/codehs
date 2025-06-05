#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    
    string phrase = "HACK Comp Sci";
    int phraseLength = phrase.length();
    
    for (int letIdx = 0; letIdx < phraseLength; letIdx++)
    {
        char let = toupper(phrase[letIdx]);
        if (let == 'A')
        {
            phrase.replace(letIdx, 1, "4");
        }
        if (let == 'E')
        {
            phrase.replace(letIdx, 1, "3");
        }
        if (let == 'O')
        {
            phrase.replace(letIdx, 1, "0");
        }
        if (let == 'I')
        {
            phrase.replace(letIdx, 1, "1");
        }
    }
    
    cout << phrase;
    
    return 0;
}