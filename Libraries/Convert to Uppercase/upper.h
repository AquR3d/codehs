#include <string>

using namespace std;

// Enter your code here
string upperCase(string &str)
{
    string newStr = "";
    for (int i = 0; i < str.size(); i++)
    {
        newStr += toupper(str[i]); 
    }
    return newStr;
}