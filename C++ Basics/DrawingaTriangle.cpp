#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    cout << "Enter triangle size: ";
    int size;
    cin >> size;
    
    for (int row = 1; row <= size; row++)
    {
        for (int space = size; space > row; space--)
        {
            cout << " ";
        }
        
        for (int star = 1; star <= 2 * row - 1; star++)
        {
            cout << "*";    
        }
        cout << endl;
    }
    
    return 0;
}