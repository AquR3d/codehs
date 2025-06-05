#include <iostream>

using namespace std;

struct song
{
    string title, artist;
    int length;
};

void printSong(song s);

int main()
{
    // Enter your code here
    
    song believer;
    believer.title = "Believer";
    believer.artist = "Imagine Dragons";
    believer.length = 207; //207 seconds
    
    song hamilton;
    hamilton.title = "Alexander Hamilton";
    hamilton.artist = "Original Broadway Cast";
    hamilton.length = 237;
    
    printSong(believer);
    printSong(hamilton);
    
    return 0;
}

void printSong(song s)
{
    cout << s.title << " by " << s.artist << " is " << s.length << " seconds long." << endl;
}