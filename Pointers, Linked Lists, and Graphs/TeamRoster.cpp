#include "util.h"
#include <map>

struct member {
    string firstName, lastName;
    int grade;
};

struct team {
    string teamName;
    vector<member *> members;
};

/* This function prints all team members 
 * first name and grade. If the team is empty,
 * it should print No members on  ____ team.
 */
void printTeam(team &t){
    
    if (t.members.empty()) {
        cout << "No members on " << t.teamName << " team.\n";
        return;
    }
    
    cout << "Team: " << t.teamName << endl;
    for (member* m : t.members) {
        cout << "Name: " << m->firstName << " - Grade: " << m->grade << endl; 
    }
}

/* This function adds a new member and puts 
* them on the overall roster. You should prompt
* for first name, last name and grade.
*/
void addMember(team &roster){
    string first = readLine("Please enter the first name: ");
    string last = readLine("Please enter the last name: ");
    int grade = readInt("Please enter the grade: ");
    
    member* m = new member;
    m->firstName = first;
    m->lastName = last;
    m->grade = grade;
    
    roster.members.push_back(m);
}

/* This function adds a new sub-team and 
 * returns the team object. You should prompt
 * for the sub-team name
 */
team addTeam(){
    
    string name = readLine("Enter the sub-team name: ");
    team subteam;
    subteam.teamName = name;

    return subteam;
}

/* This function prints out the complete roster
 * with an index value, then returns the index
 * corresponding to the selected team member.
 */
int getTeamMember(team roster){
    
    if (roster.members.size() < 1) {
        cout << "There are currently no members on the roster.\n\n";
        return -1;
    }
    
    cout << "Please select a team member by number:\n";
    for (int i = 0; i < roster.members.size(); i++) {
        cout << i << ": Name: " << roster.members[i]->firstName << " - Grade: " << roster.members[i]->grade << endl;
    }
    int tm = readInt(0, roster.members.size(), ">> ");
    cout << endl;

    return tm;
}

/* This function prints out all the sub teams 
 * with an index value and then return the 
 * index corresponding to the selected sub team.
 */
int getSubTeam(vector<team> &subTeams){
    
    if (subTeams.empty()) {
        cout << "There are currently no sub-teams.\n\n";
        return -1;
    }
    
    cout << "Please select the sub-team:\n";
    
    for (int i = 0; i < subTeams.size(); i++) {
        cout << i << ": " << subTeams[i].teamName << endl;    
    }
    int st = readInt(0, subTeams.size(), ">> ");
    cout << endl;

    return st;
}

/* This function gets a member and a sub-team from 
 * the helper methods above and then assigns the 
 * member to the sub-team.
 */
void assignToTeam(team roster, vector<team> &subTeams){
    int tm = getTeamMember(roster);
    
    if (tm == -1) return;
    
    int st = getSubTeam(subTeams);
    
    if (st == -1) return;
    
    subTeams[st].members.push_back(roster.members[tm]);
}

/* This function takes the existing members and 
 * allows updates to all the member fields. Prompt
 * the user for the memeber to update using the helper
 * function above, then prompt for a value to update,
 * but only update  if the user enters a value. If 
 * they leave the field blank, do not update.
 */
void updateMember(team roster){
    int tm = getTeamMember(roster);
    
    if (tm == -1) return;
    
    string first = readLine(roster.members[tm]->firstName + ": Enter new first name if needed: ");
    string last = readLine(roster.members[tm]->lastName + ": Enter new last name if needed: ");
    
    if (first.size() > 0)
        roster.members[tm]->firstName = first;
    if (last.size() > 0)
        roster.members[tm]->lastName = last;
    
    while (true) {
        cout << roster.members[tm]->grade << "Enter new grade if needed: ";
        string grade = readLine("");
        if (grade.size() > 0) {
            try {
                roster.members[tm]->grade = stoi(grade);
                return;
            } catch (std::invalid_argument) {}
        } else { return; }
    }
}

/* The main function prints the menu and calls the
 * helper functions. This part of the code does
 * not require any changes.
 */
int main()
{
    team totalRoster;
    totalRoster.teamName = "Complete Roster";
    vector<team> subTeams;
    
    while (true){
        cout << "Please select an option:" << endl;
        cout << "1: Add team member" << endl;
        cout << "2: Edit team member" << endl;
        cout << "3: Add sub-team" << endl;
        cout << "4: Assign team member to sub-team" << endl;
        cout << "5: Print sub-team roster" << endl;
        cout << "6: Exit" << endl;
        
        int menu = readInt(1,6, "Please enter an option: ");
        cout << endl;
        
        if (menu == 6) break;
        else if (menu == 1) addMember(totalRoster);
        else if (menu == 2) updateMember(totalRoster);
        else if (menu == 3) subTeams.push_back(addTeam());
        else if (menu == 4) assignToTeam(totalRoster, subTeams);
        else if (menu == 5) {
            int st = getSubTeam(subTeams);
            if (st == -1) continue;
            printTeam(subTeams[st]);
        }
    }
    
    return 0;
}