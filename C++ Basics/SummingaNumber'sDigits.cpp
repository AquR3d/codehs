#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    
    int num = 2349, sum = 0;
    
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    
    cout << sum;
    
    return 0;
}