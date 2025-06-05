#include <iostream>

using namespace std;

void burritoBowl(string protein, string rice = "white", string beans = "black", string salsa = "mild");

int main()
{
    //Enter your code here
    burritoBowl("chicken");
    burritoBowl("steak", "white", "refried", "hot");
    burritoBowl("veggie", "brown");
    
    return 0;
}

void burritoBowl(string protein, string rice, string beans, string salsa)
{
    cout << "Your Burrito Bowl:" << endl;
    cout << "A " << protein << " burrito with " << rice << " rice, " << beans << " beans, and " << salsa << " salsa." << endl << endl;
}