#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Enter your code here
    cout << "Please enter a file name: ";
    string fileName;
    getline(cin, fileName);
   
    ifstream in;
    in.open(fileName);
   
    double sum = 0.0;
    while (true)
    {
        string line;
        getline(in, line);
        
        if (in.fail()) { break; }
        
        sum += stod(line);
    }
   
    in.close();
   
    cout << "The sum is " << sum;
   
    return 0;
}