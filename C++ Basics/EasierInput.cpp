#include <iostream>

using namespace std;

double inputDouble(string prompt)
{
    cout << prompt; double num; cin >> num; return num;
}

int inputInt(string prompt)
{
    cout << prompt; int num; cin >> num; return num;
}

string inputLine(string prompt)
{
    cout << prompt; string words; getline(cin, words); return words;    
}

int main()
{
    // Enter your code here
    
    string name = inputLine("What is your name? ");
    
    cout << "Hi " << name << "!";
    
    return 0;
}