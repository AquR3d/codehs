#include <iostream>

using namespace std;

double inputDouble(string prompt, double min, double max, string reprompt = "Please try again: ");
int inputInt(string prompt, int min, int max, string reprompt = "Please try again: ");
double inputDouble(string prompt);
int inputInt(string prompt);

int main()
{
    // Enter your code here
    double num1 = inputDouble("Enter a double among (0-20.0): ", 0, 20, "That is not among (0-20.0). Try again: ");
    cout << "You entered: " << num1 << endl;
    
    int num2 = inputInt("Enter an int among (0-10): ", 0, 10);
    cout << "You entered: " << num2;
    
    
    return 0;
}

double inputDouble(string prompt, double min, double max, string reprompt)
{
    double num = inputDouble(prompt);
    
    while (num < min || num > max)
    {
        num = inputDouble(reprompt);
    }
    return num;
}

int inputInt(string prompt, int min, int max, string reprompt)
{
    int num = inputInt(prompt);
    
    while (num < min || num > max)
    {
        num = inputInt(reprompt);
    }
    return num;
}

double inputDouble(string prompt)
{
    cout << prompt; double num; cin >> num; return num;
}

int inputInt(string prompt)
{
    cout << prompt; int num; cin >> num; return num;
}