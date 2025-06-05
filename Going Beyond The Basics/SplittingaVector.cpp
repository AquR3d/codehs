#include <iostream>
#include <vector>

using namespace std;

vector<int> initial {8, 3, 9, 5, 14, 11, 23, 2, 6};

int main()
{
    // Enter your code here
    vector<int> even;
    vector<int> odd;
    
    for (int num : initial)
    {
        if (num % 2 == 1)
        {
            odd.push_back(num);   
        }
        else
        {
            even.push_back(num);    
        }
    }
    
    for (int num : even)
    {
        cout << num << " ";    
    }
    
    cout << endl;
    
    for (int num : odd)
    {
        cout << num << " ";    
    }
    
    return 0;
}