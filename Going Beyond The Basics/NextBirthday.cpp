#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    bool validInput = false;
    int age;
    while (!validInput)
    {
        try
        {
            cout << "Please enter your age: ";
            string line;
            getline(cin, line);
            
            age = stoi(line);
            
            if (age < 2) throw logic_error("Too young.");
            if (age > 110) throw logic_error("Too old.");
            
            validInput = true;
        }
        catch (invalid_argument)
        {
            cout << "Please enter a valid number." << endl;
        }
        catch (logic_error const& x)
        {
            cout << "Age invalid. " << x.what() << endl;
        }
    }
    
    cout << "On your next birthday, you will be " << age + 1 << " years old.";
    
    return 0;
}