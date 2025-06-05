#include <iostream>
#include <bitset>

using namespace std;

int calculateKey(int prevCode, int key);

bool comparekeys(int key1, int key2);

int calculateMatches(int empStart, int empKey, int comStart, int comKey, int times);

void printPair(int empStart, int empKey, int comStart, int comKey, int pair);

int main() {
    int emp = 686;
    int com = 1248;
    
    cout << "How many pairs of codes would you like to compare? ";
    int pairCount;
    cin >> pairCount;
    
    int valids = calculateMatches(emp, 692, com, 483, pairCount);
    
    cout << "Matches: " << valids << endl;
    
    cout << "What bitset pair would you like to print? ";
    cin >> pairCount;
    printPair(emp, 692, com, 483, pairCount);

    return 0;
}

int calculateKey(int prevCode, int key)
{
    return (prevCode * key) % 308947;    
}

bool compareKeys(int key1, int key2)
{
    return bitset<12>(key1).to_string() == bitset<12>(key2).to_string();    
}

int calculateMatches(int empStart, int empKey, int comStart, int comKey, int times)
{
    int matches = 0;
    // runs for times times
    for (int i = 0; i < times; i++)
    {
        if (compareKeys(empStart = calculateKey(empStart, empKey), comStart = calculateKey(comStart, comKey)))
        {
            matches++;
        }
    }
    
    return matches;
}

void printPair(int empStart, int empKey, int comStart, int comKey, int pair)
{
    for (int i = 0; i < pair; i++)
    {
        empStart = calculateKey(empStart, empKey);
        comStart = calculateKey(comStart, comKey);
    }
    
    cout << "EMP: " << bitset<32>(empStart).to_string() << endl;
    cout << "COM: " << bitset<32>(comStart).to_string() << endl;
}