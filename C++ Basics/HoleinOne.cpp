#include <iostream>

using namespace std;
int main()
{
    // Enter your code here
    
    string str1 = "HOLE";
    string str2 = "one";
    
    str2.insert(1, str1);
    
    cout << str2;
    
    return 0;
}