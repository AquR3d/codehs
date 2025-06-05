#include <iostream>
#include <vector>

using namespace std;

double calcOthrQrtrAvg(double currentAverage, int quartersDone, int gradeToGet)
{
    if (quartersDone > 3)
    {
        return -1;    
    }
    // ((average * quarters) + (newAverage * (4 - quarters))) / 4 = 90
    // ((90 * 4) - (average * quarters))/ (4 - quarters) = newAverage
    
    return (gradeToGet * 4.0 - (currentAverage * quartersDone)) / (4.0 - quartersDone);
}

void printResults(double averageToGet, string letterGrade)
{
    cout << "To get a " << letterGrade << " for the year, you will need to average: " << averageToGet << endl;
}

int main()
{
    // Enter your code here
    vector<double> grades;
    
    double input, quarter = 0;
    
    while (input != -1 && quarter < 3)
    {
        cout << "Please enter tour quarterly grade (-1 when finished): ";
        cin >> input;
        
        if (input == -1) { break; }
        
        grades.push_back(input);
        quarter++;
    }
    
    double average = 0;
    
    for (int grade : grades)
    {
        average += grade;    
    }
    
    average /= grades.size();
    
    if (average >= 90)
    {
        printResults(calcOthrQrtrAvg(average, quarter, 100), "A+");
        printResults(calcOthrQrtrAvg(average, quarter, 90), "A");
    }
    else if (average >= 80)
    {
        printResults(calcOthrQrtrAvg(average, quarter, 90), "A");
        printResults(calcOthrQrtrAvg(average, quarter, 80), "B");
    }
    else if (average >= 70)
    {
        printResults(calcOthrQrtrAvg(average, quarter, 80), "B");
        printResults(calcOthrQrtrAvg(average, quarter, 70), "C");
    }
    else if (average >= 60)
    {
        printResults(calcOthrQrtrAvg(average, quarter, 70), "C");
        printResults(calcOthrQrtrAvg(average, quarter, 60), "D");
    }
    else
    {
        printResults(calcOthrQrtrAvg(average, quarter, 60), "D");
        printResults(calcOthrQrtrAvg(average, quarter, 0), "F");
    }
        
    return 0;
}