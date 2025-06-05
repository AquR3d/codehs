#include <iostream>
#include <vector>

using namespace std;

vector<string> days {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

string followUpAppointment(int currentAppDay, int nextAppIncrement = 7);
void printDays();

int main()
{
    // Enter your code here
    cout << "What type of appointment do you have? ";
    string appointmentType;
    getline(cin, appointmentType);
    
    cout << "Which day is your appointment? " << endl;
    printDays();
    cout << "> ";
    int appointmentDay; // store current appointment day
    cin >> appointmentDay;
    
    string nextAppDay;
    
    if (appointmentType == "Oncologist")
        nextAppDay = followUpAppointment(appointmentDay, 2);  
        
    else if (appointmentType == "Orthodontist")
        nextAppDay = followUpAppointment(appointmentDay, 10);  
    
    else
        nextAppDay = followUpAppointment(appointmentDay);
        
    cout << "Your follow up will be on a " << nextAppDay;
    
    
    return 0;
}

string followUpAppointment(int currentAppDay, int nextAppIncrement)
{
    return days[((currentAppDay - 1) + nextAppIncrement) % 7];
}

void printDays()
{
    int i = 1;
    for (string day : days)
    {
        cout << i << ": " << day << endl;
        i++;
    }
}