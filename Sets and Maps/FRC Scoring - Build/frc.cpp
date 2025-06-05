#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include "util.h"

struct team {
    double avgPoints;
    int matchesDone, points;
};

struct match
{
    vector<int> redTeams; // team#, alliance
    vector<int> blueTeams;
};

void addPoints(team &t, int pointsToAdd);
void printMatch(match &m);
void printResults(map<int, team> &teams);
void recordMatch(match &m, map<int, team> &teams);
void readInMatches(queue<match> &matches, map<int, team> &teams);

int main() {
    // make a vector of matches to store matches data
    queue<match> matches;
    map<int, team> teams; // team#, pointData
    
    // read in matches.txt
    readInMatches(matches, teams);
    
    int matchNum = 0;
    
    // menu system
    while (true)
    {
        // prompt
        cout << "FRC Scoring System" << endl;
        cout << "1. Record a match" << endl;
        cout << "2. Print results" << endl;
        cout << "3. Exit" << endl;
        int choice = readInt("> "); // get user input
        
        // exit
        if (choice == 3) break;
        
        // record match
        if (choice == 1)
        {
            // if no matches left in the queue...
            if (matches.empty())
                cout << "No more matches to record." << endl;
            else // if there IS a match to record...
            {
                // print match data
                matchNum++;
                cout << "*** Match " << matchNum << "\t***" << endl;
                printMatch(matches.front()); // print teams
                
                // add data
                recordMatch(matches.front(), teams);
                matches.pop(); // get rid of match
            }
        }
        
        // print results
        if (choice == 2) 
        {
            if (matchNum < 1)
            {
                cout << "No match has been recorded yet." << endl;
            }
            else
            {
                cout << "**** Standings after " << matchNum << " Matches\t****" << endl;
                printResults(teams);
                cout << endl;
            }
        }
        // reloop
    }
    // end of program
    return 0;
}

void addPoints(team &t, int pointsToAdd)
{
    t.points += pointsToAdd; // add points
    t.matchesDone++; // increase matches done
    t.avgPoints = t.points / (double)t.matchesDone; // update average
}

void printMatch(match &m)
{
    cout << "Red Alliance:  ";
    // for each team in the redTeams vector in the match...
    for (int i = 0; i < m.redTeams.size(); i++)
        cout << m.redTeams[i] << " "; // print the team number
    
    cout << "\nBlue Alliance: ";
    // for each team in the blueTeams vector in the match...
    for (int i = 0; i < m.blueTeams.size(); i++)
        cout << m.blueTeams[i] << " "; // print the team number
    cout << endl;
}

void printResults(map<int, team> &teams)
{
    map<double, vector<int> > teamsRanked; // avg points, team#
    
    // organize/ rank the teams here...
    // for each team...
    for (map<int, team>::iterator rtn = teams.begin(); rtn != teams.end(); rtn++)
    {
        // if the current team has played a match...
        if ((rtn->second).matchesDone > 0)
            teamsRanked[(rtn->second).avgPoints].push_back(rtn->first); // rank them and add to new map
    }
    
    // print teams by rank/avg points
    int teamRank = 1;
    // for each ranked team...
    for (auto it = teamsRanked.crbegin(); it != teamsRanked.crend(); ++it) // some weird poop
    {
        for (int team = 0; team < it->second.size(); team++)
        {
            cout << teamRank << ".\t\b\b\b\b\b" << it->second[team] << ":\b\t " << it->first << endl;
            teamRank++;
        }
    }
    // no longer needed
    teamsRanked.clear();
}

void recordMatch(match &m, map<int, team> &teams)
{
    // get points to add to red alliance teams
    int m_points = readInt(0, 4, "Enter the red team's ranking points: ", "Ranking points should be between 0 and 4: ");
    
    // for every red team...
    for (int i = 0; i < m.redTeams.size(); i++)
        addPoints(teams[m.redTeams[i]], m_points); // add points to them
    
    // get points to add to blue alliance teams
    m_points = readInt(0, 4, "Enter the blue team's ranking points: ", "Ranking points should be between 0 and 4: ");
    
    // for every blue team...
    for (int i = 0; i < m.blueTeams.size(); i++)
        addPoints(teams[m.blueTeams[i]], m_points); // add points to them
}

void readInMatches(queue<match> &matches, map<int, team> &teams)
{
    // read in matches.txt
    ifstream in; // file stream declared
    in.open("matches.txt"); // initialized to matches.txt
    // if the file stream couldn't open the file...
    if (in.fail()) Error("matches.txt not found"); // throw error
    string buffer; // read line buffer
    while(getline(in, buffer)) // for each line in the file...
    {
        // split the line by spaces...
        vector<string> t_tmp = splitLine(buffer, ' ');
        // team buffer
        team t_buffer;
        int teamID;
        // match buffer
        match m_tmp;
        for (int redIdx = 0; redIdx < t_tmp.size() / 2; redIdx++)
        {
            teamID = stoi(t_tmp[redIdx]);
            m_tmp.redTeams.push_back(teamID); // adds a team to match
            teams[teamID]; // adds team
        }
        
        for (int blueIdx = t_tmp.size() / 2; blueIdx < t_tmp.size(); blueIdx++)
        {
            teamID = stoi(t_tmp[blueIdx]);
            m_tmp.blueTeams.push_back(teamID);
            teams[teamID];
        }
        // add match to matches list/vector
        matches.push(m_tmp);
    }
    // end of reading matches.txt
}