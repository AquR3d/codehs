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

// functions for this assignment
void searchMovies(vector<movie> &movies);
void printMovies(vector<movie> &movies);

// input functions from previous assignments (i should make this a library bruh)
string inputLine(string prompt);
double inputDouble(string prompt, double min, double max, string reprompt = "Please try again: ");
int inputInt(string prompt, int min, int max, string reprompt = "Please try again: ");
double inputDouble(string prompt, string reprompt = "Not a valid number.");
int inputInt(string prompt, string reprompt = "Not a valid number.");

int main()
{
    // Enter Your Code Here
    vector<movie> movies;
    string input;
    
    ifstream in;
    in.open("movies.txt");
    
    // read in movies.txt into the vector
    if (in.fail()) return 1;
    
    while(true)
    {
        string line;
        getline(in, line);
        
        if (in.fail()) break;
        
        istringstream stream(line);
        
        movie m;
        while(getline(stream, line, ';'))
        {
            m.title = line;
            getline(stream, line, ';');
            m.year = stoi(line);
            getline(stream, line, ';');
            m.actor = line;
            getline(stream, line, ';');
            m.rating = stod(line);
        }
        movies.push_back(m);
    }
    // file to movies completed
    
    // start prompting cycle
    while (true)
    {
        try
        {
            input = inputLine("Would you like to (s)earch, (l)ist movies, or (e)xit? ");
            
            if (input.size() > 1) throw logic_error("Enter a letter please.");
            if (input != "e" && input != "l" && input != "s") throw logic_error("Please enter an option.");
        }
        catch (logic_error const& x)
        {
            cout << x.what() << endl;
        }
        
        if (input == "e") { break; } // get out of prompting cycle
        
        if (input == "l") { printMovies(movies); }
        
        if (input == "s") { searchMovies(movies); }
        
    }
    
    return 0;
}

void searchMovies(vector<movie> &movies)
{
    // prompt
    cout << "Search menu:" << endl;
    cout << "1. Search by Title" << endl;
    cout << "2. Search by Year" << endl;
    cout << "3. Search by Actor" << endl;
    cout << "4. Search by Rating" << endl;
    
    int selection = 0;
    
    // prompting system for valid selection
    while (true)
    {
        try
        {
            selection = inputInt("Enter option: ", "Not a valid # option.");

            if (selection < 1 || selection > 4)
                throw logic_error("Please enter options 1-4.");
                
            break;
        }
        catch (logic_error const &x)
        {
            cout << x.what() << endl;    
        }
    }
    
    // once selection is valid...
    vector<movie> newMovies; // new vector for searched movies successfully found
    
    // search for movies based on title
    if (selection == 1) 
    {
        string input = inputLine("Please enter a title to search for: ");
            
        for (movie m : movies)
        {
            if (m.title.find(input) != string::npos)
                newMovies.push_back(m);
        }
    }
    // search for movies based on year
    else if (selection == 2) 
    {
        int yearMin = inputInt("Please enter the starting year to search: ", 1906, 2024, "Not a valid year. Try again: ");
        int yearMax = inputInt("Please enter the ending year to search: ", yearMin, 2024, "Not a valid year. Try again: ");
        
        for (movie m : movies)
        {
            if (m.year >= yearMin && m.year <= yearMax)
                newMovies.push_back(m);
        }
    }
    // search for movies based on actor
    else if (selection == 3) 
    {
        string input = inputLine("Please enter an actor to search for: ");
            
        for (movie m : movies)
        {
            if (m.actor.find(input) != string::npos)
                newMovies.push_back(m);
        }
    }
    // search for movies based on rating
    else if (selection == 4) 
    {
        double ratingMin = inputDouble("Please enter the starting rating to search: ", 1.0, 10.0, "Not a valid rating. Try again: ");
        double ratingMax = inputDouble("Please enter the ending rating to search: ", ratingMin, 10.0, "Not a valid rating. Try again: ");
        
        for (movie m : movies)
        {
            if (m.rating >= ratingMin && m.rating <= ratingMax)
                newMovies.push_back(m);
        }
    }
    
    printMovies(newMovies);
}

void printMovies(vector<movie> &movies)
{
    if (movies.empty()) { cout << "No movies found." << endl; return; }
    
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

double inputDouble(string prompt, double min, double max, string reprompt)
{
    while (true)
    {
        try {
            double num = inputInt(prompt);
            
            if (num < min || num > max)
                throw logic_error(reprompt);
                
            return num;
        }
        catch (logic_error const &x)
        {
            cout << x.what() << endl;
        }    
    }
}

int inputInt(string prompt, int min, int max, string reprompt)
{
    while (true)
    {
        try {
            int num = inputInt(prompt);
            
            if (num < min || num > max)
                throw logic_error(reprompt);
                
            return num;
        }
        catch (logic_error const &x)
        {
            cout << x.what() << endl;
        }    
    }
}

double inputDouble(string prompt, string reprompt)
{
    while (true)
    {
        cout << prompt;
        string strNum;
        getline(cin, strNum);
        try {
            double num = stod(strNum);
            
            return num;
        }
        catch (invalid_argument)
        {
            cout << reprompt << endl;    
        }
    }
}

int inputInt(string prompt, string reprompt)
{
    while (true)
    {
        cout << prompt;
        string strNum;
        getline(cin, strNum);
        try {
            int num = stoi(strNum);
            
            return num;
        }
        catch (invalid_argument)
        {
            cout << reprompt << endl;    
        }
    }
}