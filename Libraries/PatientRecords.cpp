#include "util.h"
#include <vector>

struct patient
{
    string name;
    double temperature;
};

int main()
{
    // Enter your code here
    vector<patient> patients;
    
    while (true)
    {
    
        string name = readLine("Please enter the patient's name ('exit' when done): ");
        
        if (name == "exit") break;
        
        double temp = readDouble(95, 106, "Please enter their temperature: ", "Temperature should be between 95 & 106: ");
        
        patient p = {name, temp};
        patients.push_back(p);
    }
    
    cout << "The following patients may attend:" << endl;
    for (patient p : patients)
    {
        if (p.temperature < 100) cout << toUpperCase(p.name) << endl;    
    }
    
    return 0;
}