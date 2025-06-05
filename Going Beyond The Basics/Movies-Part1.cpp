#include <iostream>
#include <vector>

using namespace std;

struct movie
{
    string title, actor;
    int year; // year it was made
    double rating; // 1-10
};

movie inputMovieDetails();
void printMovies(vector<movie> &movies);
double inputDouble(string prompt);
int inputInt(string prompt);
string inputLine(string prompt);

int main()
{
    // Enter Your Code Here
    vector<movie> movies;
    string input;
    
    do {
        
        input = inputLine("Would you like to (a)dd a movie, (l)ist movies, or (e)xit? ");
        
        if (input == "e") { break; }
        
        if (input == "a")
        {
            movie m = inputMovieDetails();
            movies.push_back(m);
        }
        
        if (input == "l") { printMovies(movies); }
        
    } while (input != "e");
    
    return 0;
}

movie inputMovieDetails()
{
    movie m;
    m.title = inputLine("Please enter the title: ");
    m.actor = inputLine("Please enter an actor(Last, First): ");
    m.year = inputInt("Please enter the year: ");
    m.rating = inputDouble("Please enter the rating (1-10): ");
    
    return m; 
}

void printMovies(vector<movie> &movies)
{
    if (movies.size() < 1) { cout << "No movies have been added to the list." << endl; return; }
    
    for (movie m : movies)
    {
        cout << "Title: " << m.title << endl;
        cout << "Year: " << m.year << endl;
        cout << "Actor: " << m.actor << endl;
        cout << "Rating: " << m.rating << endl << endl;
    }
}

double inputDouble(string prompt)
{
    cout << prompt; double num; cin >> num; cin.ignore(); return num;
}

int inputInt(string prompt)
{
    cout << prompt; int num; cin >> num; cin.ignore(); return num;
}

string inputLine(string prompt)
{
    cout << prompt; string words; getline(cin, words); return words;    
}