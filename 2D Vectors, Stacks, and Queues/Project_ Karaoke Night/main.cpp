#include "util.h"
#include <queue>
#include <vector>
#include <fstream>

struct song
{
    string title, artist, length;
};

vector<song> songs;
queue<string> songQueue;

string printSong(song s);
void addSong();

int main()
{
    // Enter your code here
    ifstream file;
    file.open("songs.txt");
    
    if (file.fail()) { Error("File not found. Exiting with error_code 1"); return 1; }
    
    // read in song file to vector
    string line;
    while (getline(file, line))
    {
        vector<string> songParts = splitLine(line, ';');
        song s;
        s.title = songParts[0];
        s.artist = songParts[1];
        s.length = songParts[2];
        
        songs.push_back(s);
    }

    while (true)
    {
        cout << "Would you like to:\n1. Add a song\n2. Get the next song in the queue\n3. Exit" << endl;
        string option = readLine("> ");
        
        if (option == "3") break; // exit the program
        
        if (option == "1")
        {
            addSong();
        }
        
        if (option == "2")
        {
            if (songQueue.empty()) cout << "There are no singers in the queue." << endl;
            else
            {
                cout << "Next up: " << songQueue.front() << endl;
                songQueue.pop();
            }
        }
    }
    
    return 0;
}

string printSong(song s)
{
    return s.title + " by " + s.artist;
}

void addSong()
{
    string option = readLine("Please enter the song number(enter to list songs)");
    
    // if enter...
    if (option.length() < 1)
    {
        for (int i = 1; i <= songs.size(); i++)
        {
            cout << i << " - " << printSong(songs[i - 1]) << "  " << songs[i - 1].length << endl;
        }
        addSong();
        return;
    }
    
    // this is just a lot of error handling...
    int selection;
    try
    {   
        if (option.length() != 1) throw logic_error("Not a valid selection.");
        
        selection = stoi(option);
        
        if (selection < 1 || selection > songs.size()) throw logic_error("Not a valid song index.");
    }
    catch (invalid_argument)
    {
        cout << "Please enter a number." << endl;
        addSong();
        return;
    }
    catch (logic_error const& x)
    {
        cout << x.what() << endl;
        addSong();
        return;
    }
    
    
    // add selected song to queue
    song newSong = songs[selection - 1];
    
    string newSinger = readLine("Please enter the name of the performer: ");
    songQueue.push(newSinger + " will be singing " + printSong(newSong) + ".");
}