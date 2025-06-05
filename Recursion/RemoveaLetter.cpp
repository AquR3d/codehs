#include "util.h"

// Write your recursive function here
string removeA(string s)
{
    if (s.find("A") == string::npos) return s;
    return s.substr(0, s.find("A")) + removeA(s.substr(s.find("A") + 1));
}

int main()
{
    // Enter your code here
    string word = readLine("Please enter a phrase in caps: ");
    
    cout << "Removed A's: " << removeA(word) << endl;
    
    return 0;
}