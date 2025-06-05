#include <iostream>

using namespace std;

int main()
{
    // Enter your code here
    string phrase = "Please enter your favorite ";
    
    cout << phrase << "school subject: ";
    string subject;
    getline(cin, subject);
    
    cout << phrase << "musical artist or band: ";
    string artist;
    getline(cin, artist);
    
    cout << phrase << "after-school activity: ";
    string activity;
    getline(cin, activity);
    
    phrase = "Favorite ";
    
    cout << phrase << "school subject: " << subject << endl;
    cout << phrase << "musical artist or band: " << artist << endl;
    cout << phrase << "after-school activity: " << activity;
    
    
    return 0;
}