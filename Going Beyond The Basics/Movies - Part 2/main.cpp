#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct movie
{
    string title, actor;
    int year; // year it was made
    double rating; // 1-10
};

movie addMovie(string line, char delimiter = ' ');
void printMovies(vector<movie> &movies);
string inputLine(string prompt);

int main()
{
    // Enter Your Code Here
    vector<movie> movies;
    string input;
    
    ifstream in;
    in.open("movies.txt");
    
    if (in.fail()) return 1;
    
    while(true)
    {
        string line;
        getline(in, line);
        
        if (in.fail()) break;
        
        movie m = addMovie(line, ';');
        movies.push_back(m);
    }
    
    do {
        input = inputLine("Would you like to (l)ist movies, or (e)xit? ");
        
        if (input == "e") { break; }
        
        if (input == "l") { printMovies(movies); }
        
    } while (input != "e");
    
    return 0;
}

movie addMovie(string details, char delimiter)
{
    istringstream stream(details);
    string token;
    
    int detailType = 1;
    movie m;
    while (getline(stream, token, delimiter))
    {
        if (detailType == 1) m.title = token;
        if (detailType == 2) m.year = stoi(token);
        if (detailType == 3) m.actor = token;
        if (detailType == 4) m.rating = stod(token);
        detailType++;
    }
    
    return m;
}

void printMovies(vector<movie> &movies)
{
    for (movie m : movies)
    {
        cout << "Title: " << m.title << endl;
        cout << "Year: " << m.year << endl;
        cout << "Actor: " << m.actor << endl;
        cout << "Rating: " << m.rating << endl << endl;
    }
    cout << "Total Count: " << movies.size() << endl;
}

string inputLine(string prompt)
{
    cout << prompt; string words; getline(cin, words); return words;    
}